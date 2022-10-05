import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val s = line[1].toLong()
        val adj = Array(n + 1) { mutableMapOf<Int, Long>() }
        for (j in 2..n) {
            val line = jin.readLine().split(" ")
            val a = line[0].toInt()
            val b = line[1].toInt()
            val w = line[2].toLong()
            adj[a][b] = w
            adj[b][a] = w
        }
        var moves = mutableListOf<Long>()
        fun recur(a: Int): Long {
            var subTree = if (adj[a].isEmpty()) 1L else 0L
            for ((b, w) in adj[a]) {
                adj[b].remove(a)
                val below = recur(b)
                var v = w
                while (v > 0L) {
                    moves.add((v - (v / 2L)) * below)
                    v /= 2L
                }
                subTree += below
            }
            return subTree
        }
        recur(1)
        moves.sortDescending()
        var curr = moves.sum()
        if (curr <= s) {
            out.appendln(0)
        } else {
            for (answer in 1..moves.size) {
                curr -= moves[answer - 1]
                if (curr <= s) {
                    out.appendln(answer)
                    break
                }
            }
        }
    }
    print(out)
}