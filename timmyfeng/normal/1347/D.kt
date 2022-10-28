import java.io.*
import java.util.*


	fun main(args: Array<String>) {
		val `in` = InputReader(System.`in`)
		val out = PrintWriter(System.out)
		val t = `in`.nextInt()
		for (i in 0 until t) {
			val n = `in`.nextInt()
			val a = IntArray(n)
			for (j in 0 until n) {
				a[j] = `in`.nextInt()
			}
			var ans = 0
			var ali = 0
			var bob = 0
			var pre = 0
			var l = 0
			var r = n - 1
			while (l <= r) {
				var cur = 0
				if (ans % 2 == 0) {
					while (l <= r && cur <= pre) {
						cur += a[l++]
					}
					ali += cur
				} else {
					while (r >= l && cur <= pre) {
						cur += a[r--]
					}
					bob += cur
				}
				pre = cur
				++ans
			}
			out.println("$ans $ali $bob")
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