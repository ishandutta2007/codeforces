import java.io.*
import java.util.*
import kotlin.collections.HashMap

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

    @Throws(IOException::class)
    fun solve() {
        var p = readInt()
        val n = readInt()
        val periods = TreeSet<Int>()
        val rev: MutableMap<Int, Int> = HashMap()
        while (p-- > 0) {
            val k = readInt()
            periods.add(k)
            var a = k
            while (a <= 1000000) {
                rev[a] = k
                a += k
            }
        }
        val l = IntArray(n)
        for (i in 0 until n) l[i] = readInt()
        val LAST = 1000000
        val lastAppear = IntArray(LAST + 1)
        Arrays.fill(lastAppear, -1)
        run {
            var idx = n - 1
            for (i in LAST downTo 0) {
                if (idx >= 0 && l[idx] == i) lastAppear[i] = idx-- else if (i + 1 < LAST) lastAppear[i] = lastAppear[i + 1]
            }
        }
        val tree = SegmentTree()
        var i = 0
        while (i + 1 < l.size) {
            tree.upd(i, l[i + 1] - l[i])
            i++
        }
        for (out in periods) {
            var start = l[0]
            var idx = 0 // everything up to idx has been processed
            var otherperiod = 0
            var otherlast = -1
            // pw.println("consider period " + out);
            while (true) {
                // pw.println(start + " " + idx + " " + otherperiod + " " + otherlast);
                val nextidx = if (start + out >= lastAppear.size) -1 else lastAppear[start + out]
                if (nextidx == -1) {
                    // query exact
                    if (otherlast >= 0) {
                        if (idx + 1 < n) {
                            otherperiod = gcd(otherperiod, l[idx + 1] - otherlast)
                        }
                    } else {
                        if (idx + 1 < n) {
                            otherlast = l[idx + 1]
                        }
                    }
                    // query differences
                    otherperiod = gcd(otherperiod, tree.qry(idx + 1, n - 2))
                    break
                }
                if (l[nextidx] == start + out) {
                    // idx+1 to nextidx-1 should be processed
                    if (idx + 1 <= nextidx - 1) {
                        // query exact
                        if (otherlast >= 0) {
                            otherperiod = gcd(otherperiod, l[idx + 1] - otherlast)
                        } else {
                            otherlast = l[idx + 1]
                        }
                        // query difference
                        otherperiod = gcd(otherperiod, tree.qry(idx + 1, nextidx - 2))
                        otherlast = l[nextidx - 1]
                    }
                    idx = nextidx
                } else {
                    // idx to nextidx should be processed
                    if (idx + 1 <= nextidx - 1) {
                        // query exact
                        if (otherlast >= 0) {
                            otherperiod = gcd(otherperiod, l[idx + 1] - otherlast)
                        } else {
                            otherlast = l[idx + 1]
                        }
                        // query difference
                        otherperiod = gcd(otherperiod, tree.qry(idx + 1, nextidx - 2))
                        otherlast = l[nextidx - 1]
                    }
                    idx = nextidx - 1
                }
                start += out
            }
            if (otherperiod == 0 || rev.containsKey(otherperiod)) {
                otherperiod = if (otherperiod == 0) {
                    periods.first()
                } else {
                    rev[otherperiod]!!
                }
                if (otherlast == -1) otherlast = 1
                otherlast %= otherperiod
                if (otherlast == 0) otherlast = otherperiod
                pw!!.println("YES")
                pw!!.println(l[0].toString() + " " + out)
                pw!!.println("$otherlast $otherperiod")
                return
            }
        }
        pw!!.println("NO")
    }

    fun gcd(a: Int, b: Int): Int {
        return if (b == 0) a else gcd(b, a % b)
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
        val SZ = 1 shl 17
        var tree: IntArray
        fun upd(idx: Int, `val`: Int) {
            var idx = idx
            idx += SZ
            tree[idx] = `val`
            while (idx > 1) {
                idx /= 2
                tree[idx] = gcd(tree[2 * idx], tree[2 * idx + 1])
            }
        }

        fun qry(lhs: Int, rhs: Int): Int {
            var lhs = lhs
            var rhs = rhs
            lhs += SZ
            rhs += SZ
            var ret = 0
            while (lhs <= rhs) {
                if (lhs == rhs) return gcd(ret, tree[lhs])
                if (lhs % 2 != 0) ret = gcd(ret, tree[lhs++])
                if (rhs % 2 == 0) ret = gcd(ret, tree[rhs--])
                lhs /= 2
                rhs /= 2
            }
            return ret
        }

        init {
            tree = IntArray(2 * SZ)
        }
    }