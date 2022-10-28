import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val k = `in`.nextInt()
	val x = `in`.nextInt()
	val a = IntArray(n)
	for (i in 0 until n) {
		a[i] = `in`.nextInt()
	}
	var lo: Long = 0
	var hi = 100000.toLong() * x
	while (lo < hi) {
		val m = (lo + hi) / 2
		val block = PriorityQueue(x, Collections.reverseOrder<Int>())
		var sum: Long = 0
		var need = 0
		for (i in 0 until n) {
			if (block.size == x) {
				block.clear()
				sum = 0
			}
			block.offer(a[i])
			sum += a[i]
			if (sum > m) {
				sum -= block.poll()
				++need
			}
		}
		if (need <= k) {
			hi = m
		} else {
			lo = m + 1
		}
	}
	out.println(lo)
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