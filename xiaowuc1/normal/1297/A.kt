import java.io.*
import java.util.*

/*
			  br = new BufferedReader(new FileReader("input.txt"));
			  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
			  br = new BufferedReader(new InputStreamReader(System.in));
			  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */
	private var br: BufferedReader? = null
	private var st: StringTokenizer? = null
	private var pw: PrintWriter? = null
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
		 */for (casenum in 1..qq) {
			var n = readLong()
			if (n < 1000) pw!!.println(n) else if (n < 999500) {
				n += 500
				pw!!.println((n / 1000).toString() + "K")
			} else {
				n += 500000
				pw!!.println((n / 1000000).toString() + "M")
			}
		}
		exitImmediately()
	}

	private fun exitImmediately() {
		pw!!.close()
		System.exit(0)
	}

	@Throws(IOException::class)
	private fun readLong(): Long {
		return readToken().toLong()
	}

	@Throws(IOException::class)
	private fun readDouble(): Double {
		return readToken().toDouble()
	}

	@Throws(IOException::class)
	private fun readInt(): Int {
		return readToken().toInt()
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