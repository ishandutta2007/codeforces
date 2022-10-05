import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 1000000007L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (m, n) = jin.readLine().split(" ").map { it.toInt() }
    val union = IntArray(n + 1) { it }
    fun find(u: Int): Int {
        if (union[u] != union[union[u]]) {
            union[u] = find(union[u])
        }
        return union[u]
    }
    val answer = mutableListOf<Int>()
    for (j in 1..m) {
        val line = jin.readLine().split(" ").map { it.toInt() }
        val (a, b) = if (line[0] == 1) Pair(0, line[1]) else Pair(line[1], line[2])
        if (find(a) != find(b)) {
            answer.add(j)
            union[find(a)] = find(b)
        }
    }
    var pow2 = 1L
    for (j in answer.indices) {
        pow2 *= 2L
        pow2 %= MOD
    }
    println("$pow2 ${answer.size}")
    println(answer.sorted().joinToString(" "))
}