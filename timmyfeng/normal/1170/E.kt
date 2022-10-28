import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val m = `in`.nextInt()
	val a = IntArray(n + 1)
	for (i in 1..n) {
		a[i] = `in`.nextInt()
		a[i] += a[i - 1]
	}
	val q = `in`.nextInt()
	for (qq in 0 until q) {
		val c = `in`.nextInt()
		val seg = IntArray(c + 1)
		var pre = 0
		for (i in 0 until c) {
			val w = `in`.nextInt()
			seg[i] = w - pre - 1
			pre = w
		}
		seg[c] = m - pre
		var cur = 0
		for (i in seg) {
			var lo = cur
			var hi = n
			while (lo < hi) {
				val mi = (lo + hi + 1) / 2
				if (a[mi] - a[cur] <= i) {
					lo = mi
				} else {
					hi = mi - 1
				}
			}
			cur = lo
		}
		out.println(if (cur == n) "YES" else "NO")
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