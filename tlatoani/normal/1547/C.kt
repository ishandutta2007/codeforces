import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (k, n, m) = readLine()!!.split(" ").map { it.toInt() }
        var lines = k
        val ay = ArrayDeque(readLine()!!.split(" ").map { it.toInt() })
        val by = ArrayDeque(readLine()!!.split(" ").map { it.toInt() })
        val answer = mutableListOf<Int>()
        while (ay.isNotEmpty() || by.isNotEmpty()) {
            if (ay.isNotEmpty() && (ay.first == 0 || ay.first <= lines)) {
                if (ay.first == 0) {
                    lines++
                }
                answer.add(ay.removeFirst())
            } else if (by.isNotEmpty() && (by.first == 0 || by.first <= lines)) {
                if (by.first == 0) {
                    lines++
                }
                answer.add(by.removeFirst())
            } else {
                break
            }
        }
        if (answer.size == n + m) {
            println(answer.joinToString(" "))
        } else {
            println(-1)
        }
    }
}