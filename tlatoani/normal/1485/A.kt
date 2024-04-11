import kotlin.math.min

fun main() {
    fun test(a: Int, b: Int): Int {
        if (b == 1) {
            return 1000000000
        }
        var a = a
        var answer = 0
        while (a != 0) {
            answer++
            a /= b
        }
        return answer
    }
    for (c in 1..readLine()!!.toInt()) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        var answer = 1000000000
        for (d in 0..10000) {
            answer = min(answer, d + test(a, b + d))
        }
        println(answer)
    }
}