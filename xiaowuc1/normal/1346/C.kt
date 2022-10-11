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
        val n = readInt()
        val k = readInt().toLong()
        val maxWant = n * k
        val rem = readInt()
        val rebalance = readInt()
        val l = ArrayList<Int>()
        for (i in 0 until n) {
            l.add(readInt())
        }
        Collections.sort(l)
        var totSum: Long = 0
        for (out in l) totSum += out.toLong()
        var ret = 1e18.toLong()
        if (l[l.size - 1] <= k && totSum <= maxWant) ret = Math.min(ret, 0)
        if (totSum <= maxWant) ret = Math.min(ret, rebalance.toLong())
        var curr: Long = 0
        for (i in l.indices.reversed()) {
            totSum -= l[i]
            curr += rem.toLong()
            if (totSum <= maxWant) {
                val balanced = i == 0 || l[i - 1] <= k
                ret = if (!balanced) {
                    Math.min(ret, curr + rebalance)
                } else {
                    Math.min(ret, curr)
                }
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