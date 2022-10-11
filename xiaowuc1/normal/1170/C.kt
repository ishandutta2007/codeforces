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
        //int qq = 1;
        //int qq = Integer.MAX_VALUE;
        val qq = readInt()

        /*
reminders:
arrays of objects are problematic, prefer ArrayList instead
global things must be initialized to something (explicit null)
		 */
        for (casenum in 1..qq) {
            val s = readToken()
            val t = readToken()
            var good = true
            var i = 0
            var j = 0
            while (good && i < s.length && j < t.length) {
                if (s[i] == '-' && t[j] == '-') {
                    i++
                    j++
                    continue
                }
                if (s[i] == '+' && t[j] == '+') {
                    i++
                    j++
                    continue
                }
                if (i + 1 < s.length && s[i] == '-' && s[i + 1] == '-' && t[j] == '+') {
                    i += 2
                    j++
                    continue
                }
                good = false
            }
            good = good and (i == s.length && j == t.length)
            if (good)
                pw!!.println("YES")
            else
                pw!!.println("NO")
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