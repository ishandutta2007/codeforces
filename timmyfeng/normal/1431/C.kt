import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	var t = `in`.nextInt()
	while (t-- > 0) {
		val n = `in`.nextInt()
		val k = `in`.nextInt()
		val p = IntArray(n)
		for (i in 0 until n) {
			p[i] = `in`.nextInt()
		}
		Arrays.sort(p)
		var ans = 0
		for (i in 1..n) {
			var sum = 0
			for (j in 0 until i / k) {
				sum += p[n - i + j]
			}
			ans = Math.max(ans, sum)
		}
		out.println(ans)
	}
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