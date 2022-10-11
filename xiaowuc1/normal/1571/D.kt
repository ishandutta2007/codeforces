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
        val n = readInt()
        val m = readInt()
        val g = Array(m) { IntArray(2) }
        for (i in 0 until m) {
            g[i][0] = readInt()
            g[i][1] = readInt()
        }
        val firstvote = IntArray(n + 1)
        val lastvote = IntArray(n + 1)
        val actual = Array(n + 1) { IntArray(n + 1) }
        for (i in 0 until m) {
            actual[g[i][0]][g[i][1]]++
            firstvote[g[i][0]]++
            lastvote[g[i][1]]++
        }
        var ret = 1
        for (a in 1..n) {
            for (b in 1..n) {
                if (a == b) continue
                var ourscore = 0
                if (a == g[0][0]) ourscore++
                if (b == g[0][1]) ourscore++
                val two = actual[a][b]
                val one = firstvote[a] + lastvote[b] - 2 * actual[a][b]
                if (ourscore == 0) ret = Math.max(ret, two + one + 1)
                if (ourscore == 1) ret = Math.max(ret, two + 1)
            }
        }
        pw!!.println(ret)
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