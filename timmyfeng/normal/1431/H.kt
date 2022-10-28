import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val m = `in`.nextInt()
	val k = `in`.nextInt()
	val a = LongArray(n)
	for (i in 0 until n) {
		a[i] = `in`.nextLong()
	}
	val b = LongArray(m)
	for (i in 0 until m) {
		b[i] = `in`.nextLong()
	}
	val best: MutableMap<Long, Int> = TreeMap()
	for (i in 0 until n) {
		for (j in 0 until m) {
			val c = `in`.nextInt()
			val cost = Math.max(a[i], b[j])
			if (!best.containsKey(cost) || best[cost]!! < c) {
				best[cost] = c
			}
		}
	}
	val cost: List<Long> = ArrayList(best.keys)
	val c: List<Int> = ArrayList(best.values)
	var ans = Long.MAX_VALUE
	for (i in cost.indices) {
		var favorite = 0
		var turns: Long = 0
		var sum: Long = 0
		for (j in cost.indices) {
			if (sum < cost[j]) {
				val todo = (cost[j] - sum + favorite - 1) / favorite
				sum += todo * favorite
				turns += todo
			}
			favorite = Math.max(favorite, c[j] + if (i == j) k else 0)
		}
		ans = Math.min(ans, turns)
	}
	out.println(ans)
	out.close()
}

internal class InputReader(str: InputStream?) {
	var reader: BufferedReader
	var tokenizer: StringTokenizer? = null
	operator fun next(): String {
		while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
			tokenizer = try {
				StringTokenizer(reader.readLine())
			} catch (e: IOException) {
				throw RuntimeException(e)
			}
		}
		return tokenizer!!.nextToken()
	}

	fun nextInt(): Int {
		return next().toInt()
	}

	fun nextLong(): Long {
		return next().toLong()
	}

	init {
		reader = BufferedReader(InputStreamReader(str), 1 shl 15)
	}
}