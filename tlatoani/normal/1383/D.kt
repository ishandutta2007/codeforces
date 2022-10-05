import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun adj(y: Int, x: Int) = listOf(Pair(y + 1, x), Pair(y - 1, x), Pair(y, x + 1), Pair(y, x - 1))

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val matrix = Array(n) { jin.readLine().split(" ").map { it.toInt() } }
    val all = matrix.reduce { acc, list -> acc + list }.sortedDescending()
    val rows = Array(n) { y -> matrix[y].max()!! }
    val cols = Array(m) { x -> (0 until n).map { y -> matrix[y][x] }.max()!! }
    rows.sortDescending()
    cols.sortDescending()
    //println(rows.joinToString())
    //println(cols.joinToString())
    val answer = Array(n) { IntArray(m) }
    var j = 0
    var k = 0
    val disp = TreeSet<Pair<Int, Int>>(compareBy({ it.first }, { it.second }))
    fun update(y: Int, x: Int) {
        for ((z, w) in adj(y, x)) {
            //println("try1 ($z, $w), j = $j, k = $k, answer[$z][$w] = ${if (z in 0 until n && w in 0 until m) answer[z][w] else -1}")
            if (z in 0 until j && w in 0 until k && answer[z][w] == 0) {
                //println("try2 ($z, $w)")
                var amtY = 0
                var amtX = 0
                for ((u, v) in adj(z, w)) {
                    if (u in 0 until n && v in 0 until m && answer[u][v] != 0) {
                        if (u == z) {
                            amtX++
                        } else {
                            amtY++
                        }
                    }
                }
                //println("amtY = $amtY, amtX = $amtX")
                if (amtY != 0 && amtX != 0) {
                    disp.add(Pair(z, w))
                }
            }
        }
    }
    for (a in all) {
        //answer.forEach { println(it.joinToString(" ")) }
        //println("j = $j, k = $k, a = $a")
        if ((j < n && a == rows[j]) && (k < m && a == cols[k])) {
            answer[j][k] = a
            j++
            k++
            update(j - 1, k - 1)
        } else if (j < n && a == rows[j]) {
            answer[j][k - 1] = a
            j++
            update(j - 1, k - 1)
        } else if (k < m && a == cols[k]) {
            answer[j - 1][k] = a
            k++
            update(j - 1, k - 1)
        } else {
            val (z, w) = disp.first()
            disp.remove(Pair(z, w))
            answer[z][w] = a
            update(z, w)
        }
    }
    answer.forEach { println(it.joinToString(" ")) }
}