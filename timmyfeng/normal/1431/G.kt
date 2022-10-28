import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val t = `in`.nextInt()
	val a = IntArray(n)
	for (i in 0 until n) {
		a[i] = `in`.nextInt()
	}
	Arrays.sort(a)
	val score = Array(n + 1) { IntArray(t + 1) }
	val jump = Array(n + 1) { IntArray(t + 1) }
	for (i in 1..t) {
		var j = 0
		while (j + 2 * i - 1 < n) {
			jump[j][i] = jump[j + 1][i - 1] + a[j + 2 * i - 1] - a[j]
			++j
		}
	}
	for (i in 0 until n) {
		for (j in 0..t) {
			score[i + 1][j] = Math.max(score[i + 1][j], score[i][j])
			var k = 0
			while (j + k <= t && i + 2 * k - 1 < n) {
				score[i + 2 * k][j + k] = Math.max(score[i + 2 * k][j + k], score[i][j] + jump[i][k])
				++k
			}
		}
	}
	var ans = 0
	for (i in 0..t) {
		ans = Math.max(ans, score[n][i])
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