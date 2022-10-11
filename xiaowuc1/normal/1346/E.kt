import java.io.*
import java.util.*
import kotlin.collections.HashMap

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
        solve()
        exitImmediately()
    }

    @Throws(IOException::class)
    fun solve() {
        val n = readInt()
        val m = readInt()
        val start = readInt() - 1
        val ret = IntArray(n)
        Arrays.fill(ret, 1 shl 25)
        val dp: MutableMap<Int, Int> = HashMap()
        dp[start] = 0
        for (i in 0 until m) {
            val a = readInt() - 1
            val b = readInt() - 1
            var na = 1 shl 25
            var nb = 1 shl 25
            if (dp.containsKey(a)) {
                ret[a] = Math.min(ret[a], dp[a]!!)
                nb = Math.min(nb, dp[a]!!)
                na = Math.min(na, dp[a]!! + 1)
            }
            if (dp.containsKey(b)) {
                ret[b] = Math.min(ret[b], dp[b]!!)
                na = Math.min(na, dp[b]!!)
                nb = Math.min(nb, dp[b]!! + 1)
            }
            if (na < 1 shl 25) {
                dp[a] = na
                ret[a] = Math.min(ret[a], dp[a]!!)
            }
            if (nb < 1 shl 25) {
                dp[b] = nb
                ret[b] = Math.min(ret[b], dp[b]!!)
            }
        }
        for (i in ret.indices) {
            pw!!.print(dp.getOrDefault(i, -1).toString() + " ")
        }
        pw!!.println()
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

    internal class VertexCmp : Comparator<Vertex> {
        override fun compare(a: Vertex, b: Vertex): Int {
            return a.fakedSwaps - b.fakedSwaps
        }
    }

    internal class Vertex(var timeIndex: Int, var fakedSwaps: Int, var currLocation: Int)