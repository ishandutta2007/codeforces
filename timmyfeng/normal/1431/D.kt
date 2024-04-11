import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	var t = `in`.nextInt()
	while (t-- > 0) {
		val n = `in`.nextInt()
		val a = arrayOfNulls<Pair>(n)
		for (i in 0 until n) {
			a[i] = Pair(`in`.nextInt(), i)
		}
		Arrays.sort(a)
		val ans = IntArray(n)
		ans[0] = a[n - 1]!!.b
		var big = n - 2
		var small = 1
		for (i in 0..big) {
			for (j in 0 until a[i]!!.a - 1) {
				if (small < n) {
					ans[small++] = a[big--]!!.b
				}
			}
			if (small < n) {
				ans[small++] = a[i]!!.b
			}
		}
		for (i in ans) {
			out.print((i + 1).toString() + " ")
		}
		out.println()
	}
	out.close()
}

internal class Pair(var a: Int, var b: Int) : Comparable<Pair?> {
	override operator fun compareTo(oth: Pair?): Int {
		return if (a == oth!!.a) {
			b - oth.b
		} else a - oth.a
	}

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