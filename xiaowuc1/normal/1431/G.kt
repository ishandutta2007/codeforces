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
        val n = readInt()
        val k = readInt()
        val l = IntArray(n)
        for (i in 0 until n) l[i] = readInt()
        val p = IntArray(n + 1)
        Arrays.sort(l)
        for (i in 0 until n) p[i + 1] = p[i] + l[i]
        val dp = Array(k + 1) { IntArray(n + 1) }
        for (i in 0..k) Arrays.fill(dp[i], -1)
        dp[0][0] = 0
        for (i in 0..k) {
            var best = -1
            for (j in 0 until n) {
                best = Math.max(best, dp[i][j])
                if (best < 0) continue
                var inc = 1
                while (i + inc <= k && j + 2 * inc <= n) {
                    dp[i + inc][j + 2 * inc] = Math.max(dp[i + inc][j + 2 * inc], best + p[j + 2 * inc] - 2 * p[j + inc] + p[j])
                    inc++
                }
            }
        }
        var ret = 0
        for (i in 0..n) ret = Math.max(ret, dp[k][i])
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