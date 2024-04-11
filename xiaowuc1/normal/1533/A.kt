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
        var t = readInt()
        while (t-- > 0) {
            var n = readInt()
            val k = readInt()
            var ret = 0
            while (n-- > 0) {
                val lhs = readInt()
                val rhs = readInt()
                if (lhs <= k && k <= rhs) ret = Math.max(ret, rhs - k + 1)
            }
            pw!!.println(ret)
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