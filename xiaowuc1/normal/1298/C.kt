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
			val s = readToken()
			var ret = 0
			var i = 0
			while (i < s.length) {
				if (s[i] != 'x') {
					i++

					continue
				}
				var j = i + 1
				while (j < s.length && s[j] == 'x') j++
				if (j - i >= 2) ret += j - i - 2
				i = j
			}
			pw!!.println(ret)
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
		val s: String? = br!!.readLine()
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