import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toLong() }
        println(((n - 1).toLong() * max(ay.max()!!, (ay.sum() + (n - 2).toLong()) / (n - 1).toLong())) - ay.sum())
    }
}