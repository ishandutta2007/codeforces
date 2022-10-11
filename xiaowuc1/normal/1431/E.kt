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
            val n = readInt()
            val a = IntArray(n)
            val b = IntArray(n)
            for (i in 0 until n) {
                a[i] = readInt()
            }
            for (i in 0 until n) {
                b[i] = readInt()
            }
            var offset = -1
            var best = -1
            for (off in 0 until n) {
                var cand = Int.MAX_VALUE
                for (i in 0 until n) {
                    cand = Math.min(cand, Math.abs(a[i] - b[(i + off) % n]))
                }
                if (cand > best) {
                    best = cand
                    offset = off
                }
            }
            for (i in 0 until n) {
                val want = (i + offset) % n
                pw!!.print(want + 1)
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