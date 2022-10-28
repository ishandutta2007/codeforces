import java.io.*
import java.util.*

fun main(args: Array<String>) {
	val `in` = InputReader(System.`in`)
	val out = PrintWriter(System.out)
	val n = `in`.nextInt()
	val events = ArrayList<Event>()
	for (i in 0 until n) {
		events.add(Event(`in`.nextInt(), 1))
		events.add(Event(`in`.nextInt(), -1))
	}
	Collections.sort(events)
	var cur = 0
	var y = -1
	var k = 0
	for (e in events) {
		cur += e.t
		if (cur > k) {
			k = cur
			y = e.y
		}
	}
	out.println("$y $k")
	out.close()
}

internal class Event(var y: Int, var t: Int) : Comparable<Event?> {
	override operator fun compareTo(oth: Event?): Int {
		return if (y == oth!!.y) {
			t - oth.t
		} else y - oth.y
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