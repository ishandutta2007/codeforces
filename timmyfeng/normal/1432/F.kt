import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val m = `in`.nextInt()
	val d = `in`.nextInt()
	var sum_c = 0
	val c = IntArray(m)
	for (i in 0 until m) {
		c[i] = `in`.nextInt()
		sum_c += c[i]
	}
	var index = 0
	val ans = IntArray(n)
	for (i in 0 until m) {
		index += d - 1
		index = Math.min(index, n - sum_c)
		for (j in 0 until c[i]) {
			ans[index++] = i + 1
		}
		sum_c -= c[i]
	}
	var gap = 0
	while (ans[n - 1 - gap] == 0) {
		++gap
	}
	if (gap >= d) {
		out.println("NO")
	} else {
		out.println("YES")
		for (i in ans) {
			out.print("$i ")
		}
		out.println()
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