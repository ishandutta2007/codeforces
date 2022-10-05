import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, a, b) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        val cambios = (1 until n).count { s[it] != s[it - 1] }
        println((a * n) + max(b * n, b * (1 + ((cambios + 1) / 2))))
    }
}