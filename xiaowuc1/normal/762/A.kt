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
reminders: arrays of objects are problematic, prefer ArrayList instead
		 */
        for (casenum in 1..qq) {
            val n = readLong()
            var k = readInt()
            val all = ArrayList<Long>()
            var i: Long = 1
            while (i * i <= n) {
                if (n % i == 0L) {
                    all.add(i)
                    if (i * i != n) all.add(n / i)
                }
                i++
            }
            Collections.sort(all)
            if (--k < all.size)
                pw!!.println(all[k])
            else
                pw!!.println(-1)
        }
        exitImmediately()
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