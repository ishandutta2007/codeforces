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
        val m = readInt()
        val d = readInt()
        val ret = IntArray(n + 2)
        Arrays.fill(ret, -1)
        val lens = IntArray(m)
        for (i in 0 until m) lens[i] = readInt()
        var curr = n
        for (i in m - 1 downTo 0) {
            for (j in 0 until lens[i]) {
                ret[curr--] = i
            }
        }
        curr = 0
        while (curr + d < n + 1) {
            var cand = curr
            for (i in 1..d) {
                if (ret[curr + i] >= 0) cand = curr + i
            }
            if (cand > curr) {
                curr = cand
                continue
            }
            var lhs = curr + 1
            while (lhs < ret.size && ret[lhs] == -1) lhs++
            if (lhs == ret.size) {
                pw!!.println("NO")
                exitImmediately()
            }
            var rhs = lhs + 1
            while (rhs < ret.size && ret[lhs] == ret[rhs]) {
                rhs++
            }
            rhs--
            ret[--lhs] = ret[rhs]
            ret[rhs] = -1
        }
        pw!!.println("YES")
        for (i in 1..n) {
            pw!!.print(ret[i] + 1)
            if (i == n) pw!!.println() else pw!!.print(" ")
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