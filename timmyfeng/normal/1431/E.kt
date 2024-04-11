import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	var t = `in`.nextInt()
	while (t-- > 0) {
		val n = `in`.nextInt()
		val a = IntArray(n)
		for (i in 0 until n) {
			a[i] = `in`.nextInt()
		}
		val b = IntArray(n)
		for (i in 0 until n) {
			b[i] = `in`.nextInt()
		}
		var ans = 0
		var shift = 0
		for (i in 0 until n) {
			var unfair = Int.MAX_VALUE
			for (j in 0 until n) {
				unfair = Math.min(unfair, Math.abs(a[j] - b[(j + i) % n]))
			}
			if (unfair > ans) {
				ans = unfair
				shift = i
			}
		}
		for (i in 0 until n) {
			out.print((i + shift) % n + 1)
			out.print(" ")
		}
		out.println()
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