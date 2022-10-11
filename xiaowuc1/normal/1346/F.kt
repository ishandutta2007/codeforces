import java.io.*
import java.util.*

    /*
reminders:
arrays of objects are problematic, prefer ArrayList instead
global things must be initialized to something (explicit null)
	*/
    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    fun main(args: Array<String>) {
        br = BufferedReader(InputStreamReader(System.`in`))
        pw = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)))
        solve()
        exitImmediately()
    }

    var xs: SegmentTree? = null
    var ys: SegmentTree? = null

    @Throws(IOException::class)
    fun solve() {
        xs = SegmentTree()
        ys = SegmentTree()
        val r = readInt()
        val c = readInt()
        var q = readInt()
        val g = Array(r) { IntArray(c) }
        for (i in 0 until r) {
            for (j in 0 until c) {
                g[i][j] = readInt()
                xs!!.upd(i, g[i][j].toLong())
                ys!!.upd(j, g[i][j].toLong())
            }
        }
        pw!!.print(solve(r, c))
        while (q-- > 0) {
            val a = readInt() - 1
            val b = readInt() - 1
            val w = readInt()
            xs!!.upd(a, w - g[a][b].toLong())
            ys!!.upd(b, w - g[a][b].toLong())
            g[a][b] = w
            pw!!.print(" " + solve(r, c))
        }
        pw!!.println()
    }

    fun solve(r: Int, c: Int): Long {
        val x = xs!!.medqry()
        val y = ys!!.medqry()
        var ret: Long = 0
        ret += xs!!.weiqry(x + 1, r - 1) - x * xs!!.cntqry(x + 1, r - 1)
        ret += x * xs!!.cntqry(0, x - 1) - xs!!.weiqry(0, x - 1)
        ret += ys!!.weiqry(y + 1, c - 1) - y * ys!!.cntqry(y + 1, c - 1)
        ret += y * ys!!.cntqry(0, y - 1) - ys!!.weiqry(0, y - 1)
        return ret
    }

    fun exitImmediately() {
        pw!!.close()
        System.exit(0)
    }

    @Throws(IOException::class)
    fun readInt(): Int {
        return readToken().toInt()
    }

    @Throws(IOException::class)
    fun readLong(): Long {
        return readToken().toLong()
    }

    @Throws(IOException::class)
    fun readDouble(): Double {
        return readToken().toDouble()
    }

    @Throws(IOException::class)
    fun readLine(): String? {
        val s = br!!.readLine()
        if (s == null) exitImmediately()
        st = null
        return s
    }

    @Throws(IOException::class)
    fun readToken(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(readLine()!!.trim { it <= ' ' })
        }
        return st!!.nextToken()
    }

    class SegmentTree {
        val SZ = 1 shl 10
        var sum: LongArray
        var weiSum: LongArray
        fun upd(idx: Int, delta: Long) {
            var idx = idx
            val otherDelta = idx * delta
            idx += SZ
            while (idx >= 1) {
                sum[idx] += delta
                weiSum[idx] += otherDelta
                idx /= 2
            }
        }

        fun cntqry(lhs: Int, rhs: Int): Long {
            var lhs = lhs
            var rhs = rhs
            lhs += SZ
            rhs += SZ
            var ret: Long = 0
            while (lhs <= rhs) {
                if (lhs == rhs) return ret + sum[lhs]
                if (lhs % 2 != 0) ret += sum[lhs++]
                if (rhs % 2 == 0) ret += sum[rhs--]
                lhs /= 2
                rhs /= 2
            }
            return ret
        }

        fun weiqry(lhs: Int, rhs: Int): Long {
            var lhs = lhs
            var rhs = rhs
            lhs += SZ
            rhs += SZ
            var ret: Long = 0
            while (lhs <= rhs) {
                if (lhs == rhs) return ret + weiSum[lhs]
                if (lhs % 2 != 0) ret += weiSum[lhs++]
                if (rhs % 2 == 0) ret += weiSum[rhs--]
                lhs /= 2
                rhs /= 2
            }
            return ret
        }

        fun medqry(): Int {
            var total = sum[1]
            var currIndex = 1
            while (currIndex < SZ) {
                if (2 * sum[2 * currIndex] >= total) {
                    currIndex *= 2
                } else {
                    total -= 2 * sum[2 * currIndex]
                    currIndex = 2 * currIndex + 1
                }
            }
            return currIndex - SZ
        }

        init {
            sum = LongArray(2 * SZ)
            weiSum = LongArray(2 * SZ)
        }
    }