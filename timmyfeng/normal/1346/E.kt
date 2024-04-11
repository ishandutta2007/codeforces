import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val INF = 1000000000

	val n = `in`.nextInt()
	val m = `in`.nextInt()
	val k = `in`.nextInt()
	val cost = IntArray(n + 1)
	for (i in 1..n) {
		cost[i] = if (i == k) 0 else INF
	}
	for (i in 0 until m) {
		val x = `in`.nextInt()
		val y = `in`.nextInt()
		val new_x = Math.min(cost[x] + 1, cost[y])
		val new_y = Math.min(cost[y] + 1, cost[x])
		cost[x] = new_x
		cost[y] = new_y
	}
	for (i in 1..n) {
		out.print((if (cost[i] < INF) cost[i] else -1).toString() + " ")
	}
	out.println()

	out.close()
}

internal class InputReader(str: InputStream?) {
	var read: BufferedReader
	var token: StringTokenizer? = null
	operator fun next(): String {
		while (token == null || !token!!.hasMoreTokens()) {
			token = try {
				StringTokenizer(read.readLine())
			} catch (e: IOException) {
				throw RuntimeException(e)
			}
		}
		return token!!.nextToken()
	}

	fun nextInt(): Int {
		return next().toInt()
	}

	init {
		read = BufferedReader(InputStreamReader(str), 1 shl 15)
	}
}