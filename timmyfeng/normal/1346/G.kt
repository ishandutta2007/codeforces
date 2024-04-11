import java.io.*
import java.util.*

fun gcd(a: Int, b: Int): Int {
	return if (b == 0) a else gcd(b, a % b)
}

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val k = `in`.nextInt()
	val n = `in`.nextInt()
	val p = IntArray(k)
	for (i in 0 until k) {
		p[i] = `in`.nextInt()
	}
	val x = IntArray(n)
	for (i in 0 until n) {
		x[i] = `in`.nextInt()
	}
	var ans = IntArray(0)
	if (n == 2) {
		ans = intArrayOf(x[0], p[0], x[1], p[0])
	} else {
		for (i in p) {
			if ((x[1] - x[0]) % i == 0 || (x[2] - x[0]) % i == 0) {
				var first = 1
				var prv = 0
				var res = 0
				for (j in x) {
					if (j < x[0] || (j - x[0]) % i != 0) {
						if (prv != 0) {
							res = gcd(res, j - prv)
						} else {
							first = j
						}
						prv = j
					}
				}
				for (j in p) {
					if (res % j == 0) {
						ans = intArrayOf(x[0], i, first, j)
					}
				}
			}
			if ((x[2] - x[1]) % i == 0) {
				var prv = 0
				var res = 0
				for (j in x) {
					if (j < x[1] || (j - x[1]) % i != 0) {
						if (prv != 0) {
							res = gcd(res, j - prv)
						}
						prv = j
					}
				}
				for (j in p) {
					if (res % j == 0) {
						ans = intArrayOf(x[1], i, x[0], j)
					}
				}
			}
		}
	}
	if (ans.size == 0) {
		out.println("NO")
	} else {
		out.println("YES")
		out.println(ans[0].toString() + " " + ans[1])
		out.println(ans[2].toString() + " " + ans[3])
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