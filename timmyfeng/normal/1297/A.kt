import java.io.*
import java.util.*

fun main() {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	for (t in `in`.nextInt() downTo 1)
	{
		val n = `in`.nextInt()
		if (n < 1000)
		{
			out.println(n)
		}
		else if (n < 999500)
		{
			out.println(Integer.toString((n + 500) / 1000) + "K")
		}
		else
		{
			out.println(Integer.toString((n + 500000) / 1000000) + "M")
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