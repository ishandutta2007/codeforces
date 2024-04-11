import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val w = jin.readLine().substringAfter(' ').toLong()
        val items = jin.readLine().split(" ").map { it.toLong() }.withIndex().sortedByDescending { it.value }
        val answer = mutableListOf<Int>()
        var curr = 0L
        for (item in items) {
            if (item.value <= w) {
                answer.add(item.index + 1)
                curr += item.value
                if (curr >= (w + 1L) / 2L) {
                    break
                }
            }
        }
        if (curr in (w + 1L) / 2L..w) {
            out.appendln(answer.size)
            out.appendln(answer.joinToString(" "))
        } else {
            out.appendln(-1)
        }
    }
    print(out)
}