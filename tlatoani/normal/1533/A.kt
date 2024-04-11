import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        repeat(n) {
            val (l, r) = readLine()!!.split(" ").map { it.toInt() }
            if (k in l..r) {
                answer = max(answer, r - k + 1)
            }
        }
        println(answer)
    }
}