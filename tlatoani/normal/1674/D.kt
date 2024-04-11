import kotlin.math.max
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var xs = readLine()!!.split(" ").map { it.toInt() }
        if (n % 2 == 1) {
            xs = listOf(xs.min()!!) + xs
        }
        println(if ((2 until xs.size step 2).all { j -> max(xs[j - 2], xs[j - 1]) <= min(xs[j], xs[j + 1]) }) {
            "yEs"
        } else {
            "nO"
        })
    }
}