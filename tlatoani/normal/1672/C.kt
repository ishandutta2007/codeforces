import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val equals = (1 until n).filter { xs[it - 1] == xs[it] }
        if (equals.size <= 1) {
            println(0)
        } else {
            val j = equals.first()
            val k = equals.last()
            println(max(1, k - j - 1))
        }
    }
}