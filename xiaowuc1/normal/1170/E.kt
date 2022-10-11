import java.*
import java.awt.geom.*
import java.io.*
import java.math.*
import java.text.*
import java.util.*
import java.util.regex.*

/*
			  br = new BufferedReader(new FileReader("input.txt"));
			  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
			  br = new BufferedReader(new InputStreamReader(System.in));
			  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

    private var br: BufferedReader? = null
    private var st: StringTokenizer? = null
    private var pw: PrintWriter? = null

    @Throws(IOException::class)
    fun main(args: Array<String>) {
        br = BufferedReader(InputStreamReader(System.`in`))
        pw = PrintWriter(BufferedWriter(OutputStreamWriter(System.out)))
        val qq = 1
        //int qq = Integer.MAX_VALUE;
        //int qq = readInt();

        /*
reminders:
arrays of objects are problematic, prefer ArrayList instead
global things must be initialized to something (explicit null)
		 */
        for (casenum in 1..qq) {
            val n = readInt()
            val w = readInt()
            val bad = IntArray(n)
            for (i in 0 until n) bad[i] = readInt()
            val badPref = IntArray(n + 1)
            for (i in 0 until n) badPref[i + 1] = badPref[i] + bad[i]
            var qqq = readInt()
            while (qqq-- > 0) {
                val k = readInt()
                val loc = IntArray(k)
                for (i in 0 until k) loc[i] = readInt()
                val badNeed = IntArray(k + 1)
                badNeed[0] = loc[0] - 1
                for (i in 0 until k - 1) {
                    badNeed[i + 1] = loc[i + 1] - loc[i] - 1
                }
                badNeed[k] = w - loc[k - 1]
                var idx = 0
                for (a in badNeed.indices) {
                    var lhs = idx
                    var rhs = bad.size
                    while (lhs != rhs) {
                        val mid = (lhs + rhs + 1) / 2
                        if (badPref[mid] - badPref[idx] <= badNeed[a])
                            lhs = mid
                        else
                            rhs = mid - 1
                    }
                    idx = lhs
                }
                if (idx == bad.size)
                    pw!!.println("YES")
                else
                    pw!!.println("NO")
            }
        }
        exitImmediately()
    }

    fun solve(l: IntArray, prefSum: LongArray, inc: Int, left: Int, right: Int): Long {
        // [left, right)
        var lhs = l[left].toLong()
        var rhs = l[right - 1].toLong()
        var ret = 1e18.toLong()
        while (lhs <= rhs) {
            val mid = (lhs + rhs) / 2
            var innerL = left
            var innerR = right - 1
            while (innerL < innerR) {
                val midmid = (innerL + innerR) / 2
                if (l[midmid] >= mid)
                    innerR = midmid
                else
                    innerL = midmid + 1
            }
            // [left, innerL) are < mid
            val lower = (innerL - left) * mid - (prefSum[innerL] - prefSum[left])
            // [innerL, right) are >= mid
            val higher = prefSum[right] - prefSum[innerL] - (right - innerL) * mid
            if (lower <= inc) {
                ret = Math.min(ret, lower + higher)
                lhs = mid + 1
            } else {
                rhs = mid - 1
            }
        }
        return ret
    }

    private fun exitImmediately() {
        pw!!.close()
        System.exit(0)
    }

    @Throws(IOException::class)
    private fun readLong(): Long {
        return java.lang.Long.parseLong(readToken())
    }

    @Throws(IOException::class)
    private fun readDouble(): Double {
        return java.lang.Double.parseDouble(readToken())
    }

    @Throws(IOException::class)
    private fun readInt(): Int {
        return Integer.parseInt(readToken())
    }

    @Throws(IOException::class)
    private fun readLine(): String? {
        val s = br!!.readLine()
        if (s == null) {
            exitImmediately()
        }
        st = null
        return s
    }

    @Throws(IOException::class)
    private fun readToken(): String {
        while (st == null || !st!!.hasMoreTokens()) {
            st = StringTokenizer(readLine()!!.trim { it <= ' ' })
        }
        return st!!.nextToken()
    }