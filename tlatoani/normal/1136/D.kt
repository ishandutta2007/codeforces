import java.util.*
import java.io.*

fun main() {
	val jin = BufferedReader(InputStreamReader(System.`in`))
	val (n, m) = jin.readLine().split(" ").map { it.toInt() }
	val tokenizer = StringTokenizer(jin.readLine())
	val line = IntArray(n) { tokenizer.nextToken().toInt() }
	val initial = IntArray(n + 1)
	for (j in 0 until n) {
		initial[line[j]] = j
	}
	val adj = Array(n + 1) { mutableSetOf<Int>() }
	for (j in 1..m) {
		val line = jin.readLine()
		val six = line.indexOf(' ')
		val a = line.substring(0, six).toInt()
		val b = line.substring(six + 1).toInt()
		if (initial[a] < initial[b]) {
			adj[a].add(b)
		}
	}
	val advanced = BooleanArray(n + 1)
	fun advance(j: Int): Int {
		var j = j
		if (advanced[line[j]]) {
			return j
		}
		advanced[line[j]] = true
		while (j > 0) {
			val a = line[j - 1]
			val b = line[j]
			if (b in adj[a]) {
				line[j - 1] = b
				line[j] = a
				j--
			} else {
				advance(j - 1)
				if (line[j - 1] == a) {
					return j
				}
			}
		}
		return j
	}
	val answer = n - 1 - advance(n - 1)
	println(answer)
}