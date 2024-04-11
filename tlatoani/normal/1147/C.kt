import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val piles = jin.readLine().split(" ").map { it.toInt() }
    println(if (piles.count { it == piles.min() } <= n / 2) "Alice" else "Bob")
}