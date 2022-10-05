import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val team1 = jin.readLine().split(" ").map { it.toInt() }
        val team2 = jin.readLine().split(" ").map { it.toInt() }
        val answer = IntArray(n)
        fun arrange(amt: Int): Int {
            for (j in 0 until amt) {
                answer[j] = n - amt + j
            }
            for (j in amt until n) {
                answer[j] = j - amt
            }
            return (0 until n).map { abs(team1[it] - team2[answer[it]]) }.min()!!
        }
        var optimal = arrange(0)
        var amt = 0
        for (a in 1..n) {
            val pos = arrange(a)
            if (pos > optimal) {
                optimal = pos
                amt = a
            }
        }
        arrange(amt)
        out.appendln(answer.map { it + 1 }.joinToString(" "))
    }
    print(out)
}