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
        var n = readInt()
        val q = LinkedList<Int>()
        while (n-- > 0) {
            q.addLast(readInt())
        }
        var a = 0
        var b = 0
        var last = 0
        var ret = 0
        var i = 1
        while (q.size > 0) {
            var curr = 0
            while (!q.isEmpty() && curr <= last) {
                curr += if (i % 2 == 1) {
                    q.removeFirst()
                } else {
                    q.removeLast()
                }
            }
            if (i % 2 == 1) a += curr else b += curr
            ret = i
            last = curr
            i++
        }
        pw!!.println("$ret $a $b")
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