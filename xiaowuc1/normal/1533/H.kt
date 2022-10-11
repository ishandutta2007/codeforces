import java.io.*
import java.util.*

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
to use arrays, make sure to !! after them
also .length -> .size
arrays are bad, use ArrayList instead
global things must be initialized to something (explicit null)
delete the Kotlin.throws
sort with inline comparators, you may need to non-null
do not implements Comparable 
	 */
    @Throws(IOException::class)
    fun main(args: Array<String>) {
        br = BufferedReader(InputStreamReader(System.`in`))
        pw = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)))
        solve()
        exitImmediately()
    }

    @Throws(IOException::class)
    fun solve() {
        val r = readInt()
        val c = readInt()
        val g = arrayOfNulls<String>(r)
        for (i in 0 until r) g[i] = readToken()
        val finret = LongArray(6)
        for (mask in 1..31) {
            val dp = Array(r) { IntArray(c) }
            for (a in r - 1 downTo 0) {
                for (b in 0 until c) {
                    if (mask and (1 shl g[a]!![b] - 'A') != 0) {
                        dp[a][b] = 1
                        if (a + 1 < r) dp[a][b] += dp[a + 1][b]
                    }
                }
            }
            var gain: Long = 0
            for (row in 0 until r) {
                val v = ArrayList<Int>()
                for (col in 0 until c) v.add(dp[row][col])
                gain += countRectangles(v)
            }
            for (upmask in 31 downTo 1) {
                if (upmask and mask != mask) continue
                val u = Integer.bitCount(upmask)
                val t = Integer.bitCount(mask)
                if (u % 2 == t % 2) finret[u] += gain else finret[u] -= gain
            }
        }
        for (i in 1..5) {
            pw!!.print(finret[i])
            if (i == 5) pw!!.println() else pw!!.print(' ')
        }
    }

    var SZ = 1 shl 10
    var qlb = IntArray(SZ)
    var qrb = IntArray(SZ)
    var qv = IntArray(SZ)
    private fun countRectangles(l: ArrayList<Int>): Long {
        var ret: Long = 0
        init(l)
        var ql = 0
        var qr = 0
        qlb[qr] = 0
        qrb[qr] = l.size - 1
        qv[qr] = 0
        qr++
        while (ql < qr) {
            val lhs = qlb[ql]
            val rhs = qrb[ql]
            val bound = qv[ql]
            ql++
            val data = qry(lhs, rhs)
            ret += ((rhs - lhs + 1) * (rhs - lhs + 2) * (data[0] - bound) / 2).toLong()
            if (data[1] > lhs) {
                qlb[qr] = lhs
                qrb[qr] = data[1] - 1
                qv[qr] = data[0]
                qr++
            }
            if (data[1] < rhs) {
                qlb[qr] = data[1] + 1
                qrb[qr] = rhs
                qv[qr] = data[0]
                qr++
            }
        }
        return ret
    }

    var treemv = IntArray(2 * SZ)
    var treeidx = IntArray(2 * SZ)
    fun qry(lhs: Int, rhs: Int): IntArray {
        var lhs = lhs
        var rhs = rhs
        val ret = intArrayOf(1e9.toInt(), -1)
        lhs += SZ
        rhs += SZ
        while (lhs <= rhs) {
            if (lhs % 2 != 0) {
                if (treemv[lhs] < ret[0] || treemv[lhs] == ret[0] && treeidx[lhs] < ret[1]) {
                    ret[0] = treemv[lhs]
                    ret[1] = treeidx[lhs]
                }
                lhs++
            }
            if (rhs % 2 == 0) {
                if (treemv[rhs] < ret[0] || treemv[rhs] == ret[0] && treeidx[rhs] < ret[1]) {
                    ret[0] = treemv[rhs]
                    ret[1] = treeidx[rhs]
                }
                rhs--
            }
            lhs /= 2
            rhs /= 2
        }
        return ret
    }

    fun init(l: ArrayList<Int>) {
        for (i in l.indices) {
            treemv[i + SZ] = l[i]
            treeidx[i + SZ] = i
        }
        for (i in SZ - 1 downTo 0) {
            treemv[i] = Math.min(treemv[2 * i], treemv[2 * i + 1])
            if (treemv[2 * i] < treemv[2 * i + 1]) treeidx[i] = treeidx[2 * i] else treeidx[i] = treeidx[2 * i + 1]
        }
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

    internal class State(var lhs: Int, var rhs: Int)