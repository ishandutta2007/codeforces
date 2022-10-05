import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val s = line[1].toLong()
        val adj = Array(n + 1) { mutableMapOf<Int, Pair<Int, Long>>() }
        for (j in 2..n) {
            val line = jin.readLine().split(" ")
            val a = line[0].toInt()
            val b = line[1].toInt()
            val w = line[2].toLong()
            val c = line[3].toInt()
            adj[a][b] = Pair(c, w)
            adj[b][a] = Pair(c, w)
        }
        val moves1 = mutableListOf<Long>()
        val moves2 = mutableListOf<Long>()
        fun recur(a: Int): Long {
            var subTree = if (adj[a].isEmpty()) 1L else 0L
            for ((b, p) in adj[a]) {
                val (c, w) = p
                adj[b].remove(a)
                val below = recur(b)
                var v = w
                while (v > 0L) {
                    (if (c == 1) moves1 else moves2).add((v - (v / 2L)) * below)
                    v /= 2L
                }
                subTree += below
            }
            return subTree
        }
        recur(1)
        moves1.sortDescending()
        moves2.sortDescending()
        var curr = moves1.sum() + moves2.sum()
        var k = 0
        while (k < moves2.size && curr > s) {
            curr -= moves2[k]
            k++
        }
        var answer = Int.MAX_VALUE
        if (curr <= s) {
            answer = 2 * k
        }
        for (j in 1..moves1.size) {
            curr -= moves1[j - 1]
            while (k > 0 && curr + moves2[k - 1] <= s) {
                k--
                curr += moves2[k]
            }
            if (curr <= s) {
                answer = min(answer, j + (2 * k))
            }
        }
        out.appendln(answer)
    }
    print(out)
}