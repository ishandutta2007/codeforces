import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
    val (n, u, v) = jin.readLine().split(" ").map { it.toInt() }
    val ay = jin.readLine().split(" ").map { it.toInt() }
    println(when {
        n == 1 -> -1
        ay.all { it == ay[0] } -> v + min(u, v)
        (1 until n).any { abs(ay[it] - ay[it - 1]) >= 2} -> 0
        else -> min(u, v)
    })
    }
}