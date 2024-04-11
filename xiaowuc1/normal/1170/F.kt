import java.*
import java.awt.geom.*
import java.io.*
import java.math.*
import java.text.*
import java.util.*
import java.util.regex.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

/*
			  br = new BufferedReader(new FileReader("input.txt"));
			  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
			  br = new BufferedReader(new InputStreamReader(System.in));
			  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

    private var pw: PrintWriter? = null

    internal var ret = 1e18.toLong()

    @Throws(IOException::class)
    fun main(args: Array<String>) {
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
            val (n, m, k) = readInts()
            if (m == 1) {
                pw!!.println(0)
                break
            }
            val l = readInts()
            val prefSum = LongArray(n + 1)
            Collections.sort(l)
            for (i in 0 until n) {
                prefSum[i + 1] = prefSum[i] + l[i]
            }
            for (i in 0 until n) {
                prefSum[i + 1] = prefSum[i] + l[i]
            }
            var ret = 1e18.toLong()
            var i = 0
            while (i + m <= n) {
                ret = Math.min(ret, solve(l, prefSum, k, i, i + m))
                i++
            }
            pw!!.println(ret)
        }
        exitImmediately()
    }

fun solve(l: List<Int>, prefSum: LongArray, inc: Int, left: Int, right: Int): Long {
    // [left, right)
    var lhsV = l[left].toLong()
    var rhsV = l[(left + right) / 2].toLong()
    var ret = 1e18.toLong()
    while (lhsV <= rhsV) {
        val mid = (lhsV + rhsV) / 2
        var innerL = left
        var innerR = right
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
            lhsV = mid + 1
        } else {
            rhsV = mid - 1
        }
    }
    return ret
}

    private fun exitImmediately() {
        pw!!.close()
        System.exit(0)
    }