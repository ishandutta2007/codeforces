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
			val n = readInt()
			val l = ArrayList<State>()
			for (i in 1..n) {
				val v = readInt()
				l.add(State(i, v))
			}
			for (qqq in 0 until n) {
				for (j in 1 until n) {
					if (l[j].`val` < l[j - 1].`val`) {
						val t = l[j]
						l[j] = l[j - 1]
						l[j - 1] = t
					}
				}
			}
			var last = 0
			val ret = ArrayList<Int>()
			for (out in l) {
				if (out.`val` > last) {
					last = out.`val`
					ret.add(out.idx)
				}
			}
			if (ret.size < 3) {
				pw!!.println("-1 -1 -1")
			} else {
				pw!!.println(ret[0].toString() + " " + ret[1].toString() + " " + ret[2])
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

	internal class State(var idx: Int, var `val`: Int)