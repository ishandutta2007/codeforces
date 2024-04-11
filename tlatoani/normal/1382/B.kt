import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val piles = jin.readLine().split(" ").map { it.toInt() }
        var winner = true
        for (j in n - 2 downTo 0) {
            winner = !winner || piles[j] != 1
        }
        out.appendln(if (winner) "First" else "Second")
    }
    print(out)
}