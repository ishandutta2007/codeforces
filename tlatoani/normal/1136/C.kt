import java.util.*
import java.io.*

fun main() {
	val jin = BufferedReader(InputStreamReader(System.`in`))
	val (n, m) = jin.readLine().split(" ").map { it.toInt() }
	val matrix1 = Array(n + m) { mutableListOf<Int>() }
	val matrix2 = Array(n + m) { mutableListOf<Int>() }
	for (y in 0 until n) {
		val tokenizer = StringTokenizer(jin.readLine())
		for (x in 0 until m) {
			matrix1[y + x].add(tokenizer.nextToken().toInt())
		}
	}
	for (y in 0 until n) {
		val tokenizer = StringTokenizer(jin.readLine())
		for (x in 0 until m) {
			matrix2[y + x].add(tokenizer.nextToken().toInt())
		}
	}
	matrix1.forEach { it.sort() }
	matrix2.forEach { it.sort() }
	println(if ((0 until n + m).all { matrix1[it] == matrix2[it] }) "yEs" else "nO")
}