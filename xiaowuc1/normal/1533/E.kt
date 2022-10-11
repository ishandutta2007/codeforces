import java.io.*
import java.util.*

    var br: BufferedReader? = null
    var pw: PrintWriter? = null
    var st: StringTokenizer? = null

    /*
reminders:
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
        val us = ArrayList<Int>()
        val them = ArrayList<Int>()
        load(us, n)
        load(them, n + 1)
        val pDiff = IntArray(n + 1)
        val sDiff = IntArray(n + 1)
        pDiff[0] = (-2e9).toInt()
        for (i in 0 until n) {
            pDiff[i + 1] = Math.max(pDiff[i], them[i] - us[i])
        }
        sDiff[0] = (-2e9).toInt()
        for (i in 0 until n) {
            sDiff[i + 1] = Math.max(sDiff[i], them[them.size - 1 - i] - us[us.size - 1 - i])
        }
        val q = readInt()
        for (qq in 0 until q) {
            val curr = readInt()
            // find the smallest i such that curr >= us[i]
            if (curr < us[0]) {
                pw!!.print(Math.max(sDiff[n], them[0] - curr))
            } else {
                var lhs = 0
                var rhs = us.size - 1
                while (lhs < rhs) {
                    val mid = (lhs + rhs + 1) / 2
                    if (curr >= us[mid]) lhs = mid else rhs = mid - 1
                }
                var cand = (-2e9).toInt()
                cand = Math.max(cand, pDiff[lhs + 1])
                cand = Math.max(cand, sDiff[n - lhs - 1])
                cand = Math.max(cand, them[lhs + 1] - curr)
                pw!!.print(cand)
            }
            if (qq == q - 1) pw!!.println() else pw!!.print(' ')
        }
    }

    @Throws(IOException::class)
    private fun load(l: ArrayList<Int>, k: Int) {
        var k = k
        while (k-- > 0) l.add(readInt())
        Collections.sort(l)
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