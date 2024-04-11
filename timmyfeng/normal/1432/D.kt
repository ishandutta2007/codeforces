import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	var t = `in`.nextInt()
	while (t-- > 0) {
		val n = `in`.nextInt()
		val a = `in`.nextInt()
		val b = `in`.nextInt()
		for (i in 0 until n) {
			out.print(('a'.toInt() + i % b).toChar())
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