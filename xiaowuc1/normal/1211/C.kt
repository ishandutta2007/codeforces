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
			var n = readInt()
			var want = readInt()
			var ret: Long = 0
			val l = ArrayList<State>()
			while (n-- > 0) {
				val lhs = readInt()
				val rhs = readInt()
				val w = readInt()
				want -= lhs
				ret += lhs * w.toLong()
				if (want < 0) {
					pw!!.println(-1)
					exitImmediately()
				}
				l.add(State(rhs - lhs, w))
			}
			// sort by w


			Collections.sort(l, object : Comparator<State?> {
				override fun compare(a: State?, b: State?): Int {
					return a!!.`val` - b!!.`val`
				}
			})
			for (out in l) {
				val need = Math.min(want, out.have)
				ret += need * out.`val`.toLong()
				want -= need
			}
			if (want != 0) ret = -1
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
	private fun readToken(): String? {
		while (st == null || !st!!.hasMoreTokens()) {
			st = StringTokenizer(readLine()!!.trim { it <= ' ' })
		}
		return st!!.nextToken()
	}

	internal class State(var have: Int, var `val`: Int)