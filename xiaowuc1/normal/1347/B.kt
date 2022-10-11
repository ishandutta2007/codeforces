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
        var t = readInt()
        while (t-- > 0) {
            solve()
        }
        exitImmediately()
    }

    @Throws(IOException::class)
    fun solve() {
        var a = readInt()
        var b = readInt()
        var c = readInt()
        var d = readInt()
        if (a > b) {
            a = a xor b
            b = b xor a
            a = a xor b
        }
        if (c > d) {
            c = c xor d
            d = d xor c
            c = c xor d
        }
        if (b == d && a + c == d) pw!!.println("YES") else pw!!.println("NO")
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