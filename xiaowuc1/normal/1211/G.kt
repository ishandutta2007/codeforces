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
	internal var grid: Array<IntArray?>? = null
	internal var stack: IntArray? = null
	internal var top = 0
	@Throws(IOException::class)
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
         */

		for (casenum in 1..qq) {
			val n = readInt()
			curr = IntArray(n)
			for (i in 0 until n) curr!![i] = readInt()
			want = IntArray(n)
			bad = BooleanArray(n)
			var numBad = 0
			for (i in 0 until n) {
				want!![i] = readInt()
				bad!![i] = curr!![i] != want!![i]
				if (bad!![i]) numBad++
			}
			edges = ArrayList()
			for (i in 0 until n) edges!!.add(ArrayList())
			for (i in 1 until n) {
				val a = readInt() - 1
				val b = readInt() - 1
				edges!![a].add(b)
				edges!![b].add(a)
			}
			if (numBad == 0) {
				pw!!.println("Yes")
				pw!!.println(0)
				continue
			}
			degAdj = IntArray(n)
			for (i in 0 until n) {
				if (!bad!![i]) continue
				for (out in edges!![i]) {
					if (!bad!![out]) continue
					degAdj!![i]++
				}
			}
			var root = 0
			while (root < n && (!bad!![root] || degAdj!![root] > 0)) root++
			if (root == n) {
				root = 0
				while (root < n && (!bad!![root] || degAdj!![root] > 1)) root++
			}
			if (root == n) {
				pw!!.println("No")
				continue
			}
			depth = IntArray(n)
			par = IntArray(n)
			dfs(root, -1)
			var deepestBad = -1
			var child = -1
			for (i in 0 until n) {
				if (!bad!![i]) continue
				if (depth!![i] > deepestBad) {
					deepestBad = depth!![i]
					child = i
				}
			}
			root = child
			depth!![child] = 0
			dfs(child, -1)
			deepestBad = -1
			child = -1
			for (i in 0 until n) {
				if (!bad!![i]) continue
				if (depth!![i] > deepestBad) {
					deepestBad = depth!![i]
					child = i
				}
			}
			val path = ArrayList<Int?>()
			val set: MutableSet<Int> = HashSet()
			run {
				path.add(child)
				while (child != root) {
					child = par!![child]
					path.add(child)
				}
			}
			for (out in path) set.add(out!!)
			var couldBe = true
			var i = 0
			while (couldBe && i < n) {
				if (bad!![i] && !set.contains(i)) couldBe = false
				i++
			}
			if (!couldBe) {
				pw!!.println("No")
				continue
			}
			if (valid(path)) {
				pw!!.println("Yes")
				pw!!.println(path.size)
				for (i in path.indices) {
					if (i > 0) pw!!.print(" ")
					pw!!.print(path[i]!! + 1)
				}
				pw!!.println()
				continue
			}
			Collections.reverse(path)
			if (valid(path)) {
				pw!!.println("Yes")
				pw!!.println(path.size)
				for (i in path.indices) {
					if (i > 0) pw!!.print(" ")
					pw!!.print(path[i]!! + 1)
				}
				pw!!.println()
				continue
			}
			pw!!.println("No")
		}
		exitImmediately()
	}

	fun dfs(curr: Int, pare: Int) {
		for (out in edges!![curr]) {
			if (out == pare) continue
			depth!![out] = 1 + depth!![curr]
			par!![out] = curr
			dfs(out, curr)
		}
	}

	internal var edges: ArrayList<ArrayList<Int>>? = null
	internal var bad: BooleanArray? = null
	internal var degAdj: IntArray? = null
	internal var curr: IntArray? = null
	internal var want: IntArray? = null
	internal var depth: IntArray? = null
	internal var par: IntArray? = null
	fun valid(path: ArrayList<Int?>): Boolean {
		for (i in 1 until path.size) {
			if (want!![path[i - 1]!!] != curr!![path[i]!!]) {
				return false
			}
		}
		return want!![path[path.size - 1]!!] == curr!![path[0]!!]
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