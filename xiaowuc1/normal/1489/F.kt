import java.io.*
import java.util.*

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
char[] is bad
int[] is good?
arrays are bad, use ArrayList instead
global things must be initialized to something (explicit null)
delete the Kotlin.throws
sort with inline comparators, you may need to non-null 
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
        val n = readInt()
        val m = readInt()
        val k = readInt()
        val l = IntArray(n)
        for (i in 0 until n) l[i] = readInt()
        var lhs = 0
        var rhs = n
        while (lhs < rhs) {
            val mid = (lhs + rhs + 1) / 2
            var use = 1
            var amt = k
            for (i in n - mid until n) {
                if (l[i] <= amt) {
                    amt -= l[i]
                } else {
                    use++
                    amt = k - l[i]
                }
            }
            if (use <= m) lhs = mid else rhs = mid - 1
        }
        pw!!.println(lhs)
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