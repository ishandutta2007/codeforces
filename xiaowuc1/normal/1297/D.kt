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
			val n = readInt()
			val k = readInt()
			val l = ArrayList<State>()
			for (i in 0 until n) {
				val v = readInt()
				l.add(State(i, v))
			}
			Collections.sort(l) { a, b -> b.`val` - a.`val` }
			var lhs = l[0].`val`.toLong()
			var rhs = 2.1e9.toLong()
			val ret = LongArray(n)
			while (lhs < rhs) {
				val mid = (lhs + rhs) / 2
				var maxCan = mid
				var currHave = k.toLong()
				var bad = false
				for (out in l) {
					if (out.`val` > maxCan) {
						bad = true
					} else {
						val take = Math.min(currHave, maxCan - out.`val`)
						currHave -= take
					}
					maxCan--
				}
				if (!bad && currHave == 0L) {
					rhs = mid
					Arrays.fill(ret, 0)
					maxCan = mid
					currHave = k.toLong()
					for (out in l) {
						val take = Math.min(currHave, maxCan - out.`val`)
						currHave -= take
						ret[out.loc] = take
						maxCan--
					}
				} else {
					lhs = mid + 1
				}
			}
			for (i in ret.indices) {
				if (i > 0) pw!!.print(" ")
				pw!!.print(ret[i])
			}
			pw!!.println()
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

	internal class State(var loc: Int, var `val`: Int)