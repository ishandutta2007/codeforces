import java.io.*
import java.util.*

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
arrays of objects are problematic, prefer ArrayList instead
global things must be initialized to something (explicit null)
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
        var t = readInt()
        while (t-- > 0) {
            val n = readInt()
            var k = readLong()
            val ret = ArrayList<Int>()
            run {
                val s = readLine()
                for (i in 0 until s!!.length) {
                    ret.add(s[i] - '0')
                }
            }
            var lhs = 0
            var i = 0
            while (k > 0 && i < n) {
                if (ret[i] == 1) {
                    i++
                    continue
                }
                if (i == lhs) {
                    lhs++
                    i++
                    continue
                }
                val take = Math.min(k, i - lhs.toLong())
                val actual = (i - take).toInt()
                val a = ret[i]
                val b = ret[actual]
                ret[i] = b
                ret[actual] = a
                if (actual == lhs) lhs++
                k -= take
                i++
            }
            for (out in ret) pw!!.print(out)
            pw!!.println()
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