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
			val a = readInt()
			val b = readInt()
			val k = readInt()
			val dp = TreeMap<Int, Int>()
			while (n-- > 0) {
				val x = readInt()
				dp[x] = dp.getOrDefault(x, 0) + 1
			}
			var ret = 0
			if (a <= b) {
				while (!dp.isEmpty()) {
					val `val`: Int = dp.lastKey()
					val have2 = dp.remove(`val`)!!
					if (`val` % k != 0) continue
					val below = `val` / k
					if (!dp.containsKey(below)) continue
					val have = dp.remove(below)!!
					val canTake = Math.min(have / a, have2 / b)
					ret += canTake
					if (canTake * a < have) {
						dp[below] = have - canTake * a
					}
				}
			} else {
				while (!dp.isEmpty()) {
					val `val`: Int = dp.firstKey()
					val have = dp.remove(`val`)!!
					val above = `val` * k
					if (!dp.containsKey(above)) continue
					val have2 = dp.remove(above)!!
					val canTake = Math.min(have / a, have2 / b)
					ret += canTake
					if (canTake * b < have2) {
						dp[above] = have2 - canTake * b
					}
				}
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
	private fun readToken(): String? {
		while (st == null || !st!!.hasMoreTokens()) {
			st = StringTokenizer(readLine()!!.trim { it <= ' ' })
		}
		return st!!.nextToken()
	}