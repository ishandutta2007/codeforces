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
			val m = readInt()
			val l = ArrayList<State>()
			for (i in 0 until n) {
				l.add(State(i, readInt(), readInt()))
			}
			Collections.sort(l) { a, b -> a.lhs - b.lhs }
			val ret = IntArray(n)
			val q = PriorityQueue(n, Comparator<State> { a, b -> a.rhs - b.rhs })
			var currD = 0
			var idx = 0
			var delay = 0
			while (idx < n || q.size > 0) {
				currD++
				if (q.size == 0) {
					currD = Math.max(currD, l[idx].lhs)
				}
				while (idx < l.size && l[idx].lhs == currD) {
					q.add(l[idx++])
				}
				var i = 0
				while (i < m && q.size > 0) {
					val curr = q.poll()
					ret[curr.idx] = currD
					delay = Math.max(delay, currD - curr.rhs)
					i++
				}
			}
			pw!!.println(delay)
			for (i in 0 until n) {
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

	internal class State(var idx: Int, var lhs: Int, var rhs: Int)