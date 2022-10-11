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
        var t = readInt()
        while (t-- > 0) rsolve()
    }

    @Throws(IOException::class)
    fun rsolve() {
        val n = readInt()
        var dp = IntArray(16)
        val valid = BooleanArray(16)
        valid[1 shl 3 or (1 shl 2)] = true
        valid[1 shl 3 or (1 shl 1)] = true
        val s = readToken()
        Arrays.fill(dp, 1 shl 25)
        // open 1 close 0
        run {
            var src = 0
            for (i in 0..2) {
                src *= 2
                if (s[i] == '(') src++
            }
            for (mask in 0..7) {
                dp[mask] = Integer.bitCount(mask xor src)
            }
        }
        val t = readToken()
        run {
            var i = 0
            while (i + 3 < n) {
                val ndp = IntArray(16)
                Arrays.fill(ndp, 1 shl 25)
                for (mask in 0..15) {
                    var nxt = mask * 2 and 15
                    if (s[i + 3] == '(') nxt++
                    if (t[i] == '0' || valid[nxt]) {
                        ndp[nxt] = Math.min(ndp[nxt], dp[mask])
                    }
                    nxt = nxt xor 1
                    if (t[i] == '0' || valid[nxt]) {
                        ndp[nxt] = Math.min(ndp[nxt], dp[mask] + 1)
                    }
                }
                dp = ndp
                i++
            }
        }
        var ret = dp[0]
        for (i in dp.indices) ret = Math.min(ret, dp[i])
        if (ret == 1 shl 25) ret = -1
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