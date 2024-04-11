import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val piles = jin.readLine().split(" ").map { it.toInt() }.sorted()
        var answer = 0
        for (j in 1 until n) {
            answer += (k - piles[j]) / piles[0]
        }
        out.appendln(answer)
    }
    print(out)
}