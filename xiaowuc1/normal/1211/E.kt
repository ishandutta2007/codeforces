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
			val amt = IntArray(200005)
			val l = IntArray(n)
			for (i in 0 until n) {
				l[i] = readInt()
				amt[l[i]]++
			}
			var lhs = 0
			var rhs = 200000
			while (lhs != rhs) {
				val mid = (lhs + rhs + 1) / 2
				val order = ArrayList<Int>()
				val seen: MutableSet<Int> = HashSet()
				var idx = 0
				var valid = true
				var i = 0
				while (valid && i < n) {
					if (l[i] > mid) {
						i++
						continue
					} else if (!seen.contains(l[i])) {
						order.add(l[i])
						seen.add(l[i])
					} else if (idx < order.size && order[idx] == l[i]) {
						idx++
					} else {
						valid = false
					}
					i++
				}
				valid = valid and (seen.size == mid) && idx == mid
				if (valid) lhs = mid else rhs = mid - 1
			}
			val max = lhs
			val seen = BooleanArray(n)
			val ret = CharArray(n)
			for (i in 0 until n) {
				if (l[i] > max) {
					ret[i] = 'B'
				} else if (!seen[l[i]]) {
					ret[i] = 'R'
					seen[l[i]] = true
				} else {
					ret[i] = 'G'
				}
			}
			pw!!.println(String(ret))
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