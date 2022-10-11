import java.io.*
import java.util.*
import kotlin.collections.HashSet

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
        val r = readInt()
        val c = readInt()
        val inc = readInt()
        val at = LongArray(r)
        val bt = LongArray(c)
        val dp = Array(r) { IntArray(c) }
        for (i in 0 until r) at[i] = readLong()
        for (i in 0 until c) bt[i] = readLong()
        val allt = ArrayList<Long>()
        run {
            val s: MutableSet<Long> = HashSet()
            for (out in at) s.add(out)
            for (out in bt) s.add(out)
            for (out in s) allt.add(out)
            Collections.sort(allt)
        }
        for (i in 0 until r) {
            for (j in 0 until c) {
                dp[i][j] = readInt()
                if (i > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j])
                if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - 1])
            }
        }
        var ret = allt[allt.size - 1]
        for (buy in allt.indices) {
            var curr: Long = 0
            val specialbuy = inc + dp[actualFloor(at, allt[buy])][actualFloor(bt, allt[buy])]
            var currbuy = 0
            var lhs = 0
            var rhs = 0
            var idx = 0
            var t: Long = 0
            while (curr < allt[allt.size - 1]) {
                while (lhs + 1 < at.size && at[lhs + 1] <= curr) lhs++
                while (rhs + 1 < bt.size && bt[rhs + 1] <= curr) rhs++
                currbuy = Math.max(currbuy, dp[lhs][rhs])
                if (curr >= allt[buy]) currbuy = Math.max(currbuy, specialbuy)
                while (curr >= allt[idx]) idx++
                val jump = (allt[idx] - curr + currbuy - 1) / currbuy
                t += jump
                curr += jump * currbuy
            }
            ret = Math.min(ret, t)
        }
        pw!!.println(ret)
    }

    fun actualFloor(l: LongArray, t: Long): Int {
        var lhs = 0
        var rhs = l.size - 1
        while (lhs < rhs) {
            val mid = (lhs + rhs + 1) / 2
            if (l[mid] <= t) lhs = mid else rhs = mid - 1
        }
        return lhs
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