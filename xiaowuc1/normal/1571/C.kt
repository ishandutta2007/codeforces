import java.io.*
import java.util.*

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
delete JVMStatic
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
            var lhs = 0
            var rhs = 1e9.toInt()
            var n = readInt()
            while (n-- > 0) {
                val a = readToken()
                val b = readToken()
                val k = readInt()
                var match = 0
                while (match < a.length && match < b.length) {
                    if (a[a.length - 1 - match] == b[b.length - 1 - match]) match++ else break
                }
                if (k == 1) {
                    rhs = Math.min(rhs, match)
                } else {
                    lhs = Math.max(lhs, match + 1)
                }
            }
            if (lhs > rhs) {
                pw!!.println(0)
                continue
            }
            pw!!.println(rhs - lhs + 1)
            for (i in 0 until rhs - lhs + 1) {
                pw!!.print(lhs + i)
                if (i + 1 != rhs - lhs + 1) pw!!.print(" ")
            }
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