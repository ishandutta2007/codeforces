import java.io.*
import java.util.*

fun min_element(a: LongArray): Long {
	var mn = a[0]
	for (i in 1 until a.size) {
		mn = Math.min(mn, a[i])
	}
	return mn
}

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val m = `in`.nextInt()
	val q = `in`.nextInt()
	val a = Array(n) { IntArray(m) }
	val row = LongArray(n)
	val col = LongArray(m)
	for (i in 0 until n) {
		for (j in 0 until m) {
			a[i][j] = `in`.nextInt()
			row[i] += a[i][j].toLong()
			col[j] += a[i][j].toLong()
		}
	}
	val cost_row = LongArray(n)
	for (i in 0 until n) {
		for (j in 0 until n) {
			cost_row[i] += Math.abs(i - j) * row[j].toLong()
		}
	}
	val cost_col = LongArray(m)
	for (i in 0 until m) {
		for (j in 0 until m) {
			cost_col[i] += Math.abs(i - j) * col[j].toLong()
		}
	}
	out.print(min_element(cost_col) + min_element(cost_row))
	for (i in 0 until q) {
		val x = `in`.nextInt() - 1
		val y = `in`.nextInt() - 1
		val delta = `in`.nextInt() - a[x][y]
		for (j in 0 until n) {
			cost_row[j] += Math.abs(j - x) * delta.toLong()
		}
		for (j in 0 until m) {
			cost_col[j] += Math.abs(j - y) * delta.toLong()
		}
		a[x][y] += delta
		out.print(" " + (min_element(cost_col) + min_element(cost_row)))
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