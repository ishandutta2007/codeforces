import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val players = jin.readLine().split(" ").withIndex().map { (j, s) -> Player(s.toLong(), j + 1) }.sortedBy { it.tokens }
        var curr = 0L
        var req = 0
        for (j in 0 until n - 1) {
            curr += players[j].tokens
            if (curr < players[j + 1].tokens) {
                req = j + 1
            }
        }
        println(n - req)
        println(players.subList(req, n).map { it.index }.sorted().joinToString(" "))
    }
}

data class Player(val tokens: Long, val index: Int)