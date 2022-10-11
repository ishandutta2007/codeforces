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
			val edges = ArrayList<ArrayList<Int>>()
			for (i in 0..n) {
				edges.add(ArrayList())
			}
			val deg = IntArray(n + 1)
			val bad = BooleanArray(n + 1)
			for (i in 1 until n) {
				val a = readInt()
				val b = readInt()
				edges[a].add(b)
				edges[b].add(a)
				deg[a]++
				deg[b]++
			}
			var numLeaves = 0
			val q = LinkedList<Int>()
			for (i in 1..n) {
				if (deg[i] == 1) {
					numLeaves++
					q.add(i)
				}
			}
			while (!q.isEmpty() && numLeaves > k) {
				val curr = q.removeFirst()
				numLeaves--
				bad[curr] = true
				for (out in edges[curr]) {
					if (--deg[out] == 1) {
						numLeaves++
						q.addLast(out)
					}
				}
			}
			if (numLeaves != k) {
				pw!!.println("No")
			} else {
				pw!!.println("Yes")
				val ret = ArrayList<Int>()
				for (i in 1..n) {
					if (!bad[i]) ret.add(i)
				}
				pw!!.println(ret.size)
				for (i in ret.indices) {
					if (i > 0) pw!!.print(" ")
					pw!!.print(ret[i])
				}
				pw!!.println()
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