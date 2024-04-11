import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val islands = Array(n) {
        val (l, r) = jin.readLine().split(" ").map { it.toLong() }
        Pair(l, r)
    }
    val betweens = Array(n - 1) { Between(islands[it + 1].first - islands[it].second, islands[it + 1].second - islands[it].first, it) }
    betweens.sortBy { it.ceil }
    val bridges = TreeSet<Pair<Long, Int>>(compareBy({ it.first }, { it.second }))
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..m) {
        bridges.add(Pair(tokenizer.nextToken().toLong(), j))
    }
    val answer = IntArray(n - 1)
    for (between in betweens) {
        val bridge = bridges.ceiling(Pair(between.floor, 0))
        if (bridge == null || bridge.first > between.ceil) {
            println("No")
            return
        }
        bridges.remove(bridge)
        answer[between.ix] = bridge.second
    }
    println("Yes")
    println(answer.joinToString(" "))
}

data class Between(val floor: Long, val ceil: Long, val ix: Int)