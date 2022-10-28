import kotlin.math.abs

fun main() {
    val (a, b, s) = readLine()!!.split(" ").map { it.toInt() }
    println(if (abs(a) + abs(b) <= s && s % 2 == abs(a + b) % 2) "Yes" else "No")
}