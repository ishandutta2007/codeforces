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
        val rem = readInt()
        val block = readInt()
        val l = LongArray(n)
        for (i in 0 until n) l[i] = readLong()
        var lhs: Long = 0
        var rhs = 1e10.toLong()
        while (lhs < rhs) {
            val mid = (lhs + rhs) / 2
            var added = 0
            val dp = TreeMap<Long, Int>()
            var sum: Long = 0
            var canRemove = rem
            var bad = false
            var i = 0
            while (!bad && i < n) {
                added++
                dp[l[i]] = dp.getOrDefault(l[i], 0) + 1
                sum += l[i]
                if (added == block && sum <= mid) {
                    dp.clear()
                    added = 0
                    sum = 0
                }
                if (added == block) {
                    if (canRemove == 0) {
                        bad = true
                    }
                    canRemove--
                    added--
                    val highest = dp.lastKey()
                    if (dp[highest] == 1) dp.remove(highest) else dp[highest] = dp[highest]!! - 1
                    sum -= highest
                }
                i++
            }
            while (!bad && sum > mid && dp.size > 0 && canRemove > 0) {
                canRemove--
                val highest = dp.lastKey()
                if (dp[highest] == 1) dp.remove(highest) else dp[highest] = dp[highest]!! - 1
                sum -= highest
            }
            bad = bad or (sum > mid)
            if (bad) {
                lhs = mid + 1
            } else {
                rhs = mid
            }
        }
        pw!!.println(lhs)
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