import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toLong() }
    val chains = jin.readLine().split(" ").map { it.toLong() }.sortedDescending()
    if (1L + chains.sum() - (2L * n) < k) {
        println(-1)
    } else {
        val ys = Array(2 * (n.toInt() + 1)) { mutableListOf<Long>() }
        var upper = 2L * k
        var lower = 0L
        while (upper > lower) {
            ys.forEach { it.clear() }
            val mid = (upper + lower) / 2L
            var amt = 1L
            ys[0].add(0)
            var x = 0L
            var j = 0
            for (chain in chains) {
                if (x >= mid - 1L) {
                    break
                }
                val y = ys[x.toInt()][j]
                if (x < y) {
                    ys[(x + 1L).toInt()].add(y)
                }
                val l = min(chain, (2L * (mid - x)) - 1L)
                amt += l - 2L
                ys[(x + 2L).toInt()].add(x + 1L + ((l - 1L) / 2L))
                ys[(x + 2L).toInt()].add(x + 1L + (l / 2L))
                j++
                while (j == ys[x.toInt()].size) {
                    x++
                    j = 0
                }
            }
            if (amt >= k) {
                upper = mid
            } else {
                lower = mid + 1L
            }
        }
        println(upper)
    }
}