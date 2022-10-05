import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        var (n, a, b) = readLine()!!.split(" ").map { it.toLong() }
        b = min(b, 2L * a)
        println(((n / 2L) * b) + ((n % 2L) * a))
    }
}