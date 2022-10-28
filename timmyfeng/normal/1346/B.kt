import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val t = `in`.nextInt()
	for (tt in 0 until t) {
		val n = `in`.nextInt()
		val k1 = `in`.nextInt()
		val k2 = Math.min(k1 * 2, `in`.nextInt())
		val s = `in`.next()
		var ans: Long = 0
		var i = 0
		while (i < n) {
			if (s[i] === '0') {
				++i
				continue
			}
			if (i + 1 < n && s[i + 1] === '1') {
				ans += k2.toLong()
				++i
			} else {
				ans += k1.toLong()
			}
			++i
		}
		out.println(ans)
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