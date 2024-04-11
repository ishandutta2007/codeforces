import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	var t = `in`.nextInt()
	while (t-- > 0) {
		val n = `in`.nextInt()
		var k = `in`.nextLong()
		val s = `in`.next()
		var zeroes = 0
		val ans = StringBuffer()
		for (i in 0 until n) {
			if (s[i] == '0') {
				if (ans.length <= k) {
					k -= ans.length.toLong()
					++zeroes
				} else {
					ans.insert(k.toInt(), '0')
					break
				}
			} else {
				ans.append('1')
			}
		}
		while (zeroes-- > 0) {
			ans.append('0')
		}
		ans.reverse()
		ans.append(s.substring(ans.length))
		out.println(ans)
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