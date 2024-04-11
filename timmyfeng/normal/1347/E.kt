import java.io.*
import java.util.*

	fun main(args: Array<String>) {
		val `in` = InputReader(System.`in`)
		val out = PrintWriter(System.out)
		val t = `in`.nextInt()
		for (tt in 0 until t) {
			val n = `in`.nextInt()
			if (n < 4) {
				out.println(-1)
			} else {
				run {
					var i = if (n % 2 == 1) n - 1 else n
					while (i > 4) {
						out.print("$i ")
						i -= 2
					}
				}
				out.print("2 4")
				var i = 1
				while (i <= n) {
					out.print(" $i")
					i += 2
				}
				out.println()
			}
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