import java.util.*
import java.io.*

fun main() {
	val jin = BufferedReader(InputStreamReader(System.`in`))
	val n = jin.readLine().toInt()
	val chapters = Array(n) {
		val (l, r) = jin.readLine().split(" ").map { it.toInt() }
		Pair(l, r)
	}
	val k = jin.readLine().toInt()
	var answer = 0
	for (chapter in chapters) {
		if (k <= chapter.second) {
			answer++
		}
	}
	println(answer)
}