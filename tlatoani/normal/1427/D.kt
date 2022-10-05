import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    if (n == 1) {
        println(0)
        return
    }
    var cards = jin.readLine().split(" ").map { it.toInt() }
    val out = StringBuilder()
    var operationAMT = 0
    fun operation(vararg segments: Int) {
        val segments = segments.toMutableList()
        segments.removeAll { it == 0 }
        if (segments.size > 1) {
            operationAMT++
            var new = listOf<Int>()
            for (segment in segments) {
                new = cards.subList(0, segment) + new
                cards = cards.subList(segment, cards.size)
            }
            cards = new
            out.appendln(segments.size)
            out.appendln(segments.joinToString(" "))
        }
    }
    var left = 0
    var right = 0
    for (j in n downTo 1) {
        val k = if (j % 2 == 1) (((n - j) / 2) + 1) else (((n - j) / 2) + 1 + ((n + 1) / 2))
        val ix = cards.indexOf(k)
        operation(left, ix - left, n - ix - right, right)
        val temp = left
        left = right
        right = temp
        left++
    }
    println(operationAMT)
    print(out)
}