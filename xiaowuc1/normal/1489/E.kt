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
        var q = readInt()
        val use = IntArray(500000)
        var lhs = 250000
        var rhs = lhs
        val loc = IntArray(500000)
        Arrays.fill(loc, -1)
        while (q-- > 0) {
            val s = readToken()
            val id = readInt()
            if (s == "L") {
                use[lhs] = id
                loc[id] = lhs
                if (lhs == rhs) rhs++
                lhs--
            } else if (s == "R") {
                use[rhs] = id
                loc[id] = rhs
                if (lhs == rhs) lhs--
                rhs++
            } else {
                var ret = Math.abs(lhs + 1 - loc[id])
                ret = Math.min(ret, Math.abs(rhs - 1 - loc[id]))
                pw!!.println(ret)
            }
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