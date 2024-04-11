import java.io.*
import java.util.*

	fun main(args: Array<String>) {
		val `in` = InputReader(System.`in`)
		val out = PrintWriter(System.out)
		val t = `in`.nextInt()
		for (i in 0 until t) {
			var a = `in`.nextInt()
			var b = `in`.nextInt()
			var c = `in`.nextInt()
			var d = `in`.nextInt()
			if (a > b) {
				val tmp = a
				a = b
				b = tmp
			}
			if (c > d) {
				val tmp = c
				c = d
				d = tmp
			}
			out.println(if (a + c == b && b == d) "YES" else "NO")
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