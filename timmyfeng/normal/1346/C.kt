import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val t = `in`.nextInt()
	for (tt in 0 until t) {
		val n = `in`.nextInt()
		val k = `in`.nextInt()
		val x = `in`.nextInt()
		val y = `in`.nextInt()
		val a = IntArray(n)
		var sum: Long = 0
		for (i in 0 until n) {
			a[i] = `in`.nextInt()
			sum += a[i]
		}
		Arrays.sort(a)
		var ans = 0
		var cur = 0
		var i = n - 1
		while (i >= 0 && a[i] > k) {
			if (sum > k.toLong() * n) {
				ans += x
				sum -= a[i]
			}
			cur += x
			--i
		}
		out.println(Math.min(ans + y, cur))
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