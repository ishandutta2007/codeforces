import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ").map { it.toLong() }
        val n = line[0].toInt()
        val k = line[1]
        val x = line[2]
        val y = line[3]
        val bookshelves = jin.readLine().split(" ").map { it.toLong() }.sortedDescending()
        var answer1 = 0L
        for (j in 0 until n) {
            if (bookshelves[j] <= k) {
                break
            }
            answer1 += x
        }
        var overall = bookshelves.sum()
        var answer2 = y
        for (j in 0 until n) {
            if (overall <= n.toLong() * k) {
                break
            }
            answer2 += x
            overall -= bookshelves[j]
        }
        out.appendln(min(answer1, answer2))
    }
    print(out)
}