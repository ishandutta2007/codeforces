import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val t = `in`.nextInt()
	for (i in 0 until t) {
		val n = `in`.nextInt()
		val k = `in`.nextInt()
		var factor = 0
		var base = 1
		for (j in 0..3) {
			factor += base
			base *= k
		}
		val coef = n / factor
		base = 1
		for (j in 0..3) {
			out.print((base * coef).toString() + " ")
			base *= k
		}
		out.println();
	}
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