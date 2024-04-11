import java.io.*
import java.util.*

	fun main(args: Array<String>) {
		val `in` = InputReader(System.`in`)
		val out = PrintWriter(System.out)
		val t = `in`.nextInt()
		for (i in 0 until t) {
			var n = `in`.nextInt()
			var base = 1
			val ans: MutableList<Int> = ArrayList()
			while (n > 0) {
				if (n % 10 > 0) {
					ans.add(n % 10 * base)
				}
				n /= 10
				base *= 10
			}
			println(ans.size)
			for (j in ans) {
				print("$j ")
			}
			println()
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