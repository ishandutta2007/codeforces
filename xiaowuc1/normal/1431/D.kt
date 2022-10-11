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
            val l = ArrayList<State>()
            val n = readInt()
            for (i in 0 until n) {
                l.add(State(readInt(), i + 1))
            }
            Collections.sort(l) { a, b -> a.a - b.a }
            val ret = IntArray(n)
            var used = 0
            for (i in 0 until n) {
                if (l[0].a <= used) {
                    ret[i] = l[0].b
                    l.removeAt(0)
                    used = 0
                } else {
                    ret[i] = l[l.size - 1].b
                    l.removeAt(l.size - 1)
                }
                used++
            }
            for (i in 0 until n) {
                pw!!.print(ret[i])
                if (i == n - 1) pw!!.println() else pw!!.print(" ")
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

    internal class State(var a: Int, var b: Int)