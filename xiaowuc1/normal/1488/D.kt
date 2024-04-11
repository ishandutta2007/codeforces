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
        while (t-- > 0) {
            rsolve()
        }
    }

    @Throws(IOException::class)
    fun rsolve() {
        val n = readLong()
        val s = readLong()
        var lhs: Long = 1
        var rhs = s
        while (lhs < rhs) {
            val mid = (lhs + rhs + 1) / 2
            var currs: Long = 0
            var amtleft = n
            var currv = mid
            while (currv > 1 && amtleft > 0) {
                amtleft--
                currs += currv
                currv = (currv + 1) / 2
            }
            currs += amtleft
            if (currs <= s) {
                lhs = mid
            } else {
                rhs = mid - 1
            }
        }
        pw!!.println(lhs)
    }

    /*
	public static void rsolve() throws IOException {
		int n = readInt();
		int a = readInt();
		int b = readInt();
		if(n == 2) {
			pw.println(0);
			return;
		}
		if(a > b) {
			a ^= b;
			b ^= a;
			a ^= b;
		}
		int ret = 0;
		// Case 1 - walk towards each other and keep going
		ret = Math.max(n-a, b-1);
		// Case 2 - walk away from each other and then to the center
		
		// Case 3 - walk towards each other, then bounce away
		pw.println(ret);
	}
	 */
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