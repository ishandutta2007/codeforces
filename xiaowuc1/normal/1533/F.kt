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
        val s = readToken()
        val p = IntArray(s.length + 1)
        for (i in 0 until s.length) {
            p[i + 1] = p[i] + (s[i] - '0').toInt()
        }
        for (a in 1..s.length) {
            var curr = 0
            var ret = 0
            while (curr < s.length) {
                var one = p[s.length] - p[curr]
                var zero = s.length - curr - one
                if (one <= a || zero <= a) {
                    ret++
                    break
                }
                var lhs = curr + 1
                var rhs = s.length - 1
                while (lhs < rhs) {
                    val mid = (lhs + rhs + 1) / 2
                    one = p[mid] - p[curr]
                    zero = mid - curr - one
                    if (one <= a || zero <= a) lhs = mid else rhs = mid - 1
                }
                curr = lhs
                ret++
            }
            pw!!.print(ret)
            if (a == s.length) pw!!.println() else pw!!.print(' ')
        }
    }

    @Throws(IOException::class)
    private fun load(l: ArrayList<Int>, k: Int) {
        var k = k
        while (k-- > 0) l.add(readInt())
        Collections.sort(l)
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