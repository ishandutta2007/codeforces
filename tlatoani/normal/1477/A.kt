import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val k = jin.readLine().substringAfter(' ').toLong()
        val xs = jin.readLine().split(" ").map { it.toLong() }
        var g = 0L
        for (j in 1 until xs.size) {
            g = gcd(g, abs(xs[j] - xs[0]))
        }
        out.appendln(if ((k - xs[0]) % g == 0L) "yEs" else "nO")
    }
    print(out)
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)