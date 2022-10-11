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
	internal var grid: Array<IntArray>? = null
	internal var stack: IntArray? = null
	internal var top = 0
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
			stack = IntArray(n + 1)
			grid = Array(6) { IntArray(6) }
			val edges = ArrayList<ArrayList<ArrayList<Int>>>()
			for (i in 0..5) {
				val t = ArrayList<ArrayList<Int>>()
				for (j in 0..5) {
					t.add(ArrayList())
				}
				edges.add(t)
			}
			for (i in 1..n) {
				val s = readToken()
				val a = "kotlin".indexOf(s[0])
				var b = "kotlin".indexOf(s[s.length - 1])
				b = (b + 1) % 6
				grid!![b][a]++
				edges[a][b].add(i)
			}
			euler(0)
			for (i in 1 until stack!!.size) {
				if (i > 1) pw!!.print(" ")
				val choice = edges[stack!![i - 1]][stack!![i]]
				pw!!.print(choice.removeAt(choice.size - 1))
			}
			pw!!.println()
		}
		exitImmediately()
	}

	fun euler(x: Int) {
		for (i in 0..5) {
			while (grid!![x][i] > 0) {
				grid!![x][i]--
				euler(i)
			}
		}
		stack!![top++] = x
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