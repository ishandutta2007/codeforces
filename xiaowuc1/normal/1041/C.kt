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
        for (casenum in 1..qq) {
            val n = readInt()
            val m = readInt()
            val d = readInt()
            val l = arrayOfNulls<State>(n)
            for (i in 0 until n) l[i] = State(readInt(), i)
            Arrays.sort(l)
            val ret = IntArray(n)
            var ans = 0
            var lhs = 0
            for (i in 0 until n) {
                if (i > lhs && l[i]!!.`val` - l[lhs]!!.`val` > d) {
                    ret[l[i]!!.idx] = ret[l[lhs++]!!.idx]
                } else {
                    ret[l[i]!!.idx] = ++ans
                }
            }
            pw!!.println(ans)
            for (out in ret) pw!!.print("$out ")
            pw!!.println()
        }
        exitImmediately()
    }

    internal class State(var `val`: Int, var idx: Int) : Comparable<State> {
        override fun compareTo(s: State): Int {
            return `val` - s.`val`
        }
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