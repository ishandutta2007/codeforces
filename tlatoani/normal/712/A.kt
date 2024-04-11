import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val ay = jin.readLine().split(" ").map { it.toLong() } + listOf(0L)
    val answer = LongArray(n) { ay[it] + ay[it + 1] }
    println(answer.joinToString(" "))
}