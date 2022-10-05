import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val xs = jin.readLine().split(" ").map { it.toLong() }.sorted()
    var numerator = 0L
    for (j in 0 until n) {
        numerator += (3L + (4L * j.toLong()) - (2L * n.toLong())) * xs[j]
    }
    val g = gcd(numerator, n.toLong())
    println("${numerator / g} ${n.toLong() / g}")
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)