import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m, q) = jin.readLine().split(" ").map { it.toInt() }
    val answer = IntArray(q + 1)
    val dummy = IntArray(n + 1)
    val last = Array(q + 1) { dummy }
    val shelves = Array(q + 1) { BitSet(m) }
    for (j in 1..q) {
        val query = jin.readLine().split(" ").map { it.toInt() }
        if (query[0] < 4) {
            answer[j] = answer[j - 1]
            last[j] = last[j - 1].copyOf()
            val s = query[1] - 1
            shelves[j].or(shelves[last[j][s]])
            last[j][s] = j
            when (query[0]) {
                1 -> {
                    if (!shelves[j].get(query[2] - 1)) {
                        answer[j]++
                        shelves[j].set(query[2] - 1)
                    }
                }
                2 -> {
                    if (shelves[j].get(query[2] - 1)) {
                        answer[j]--
                        shelves[j].set(query[2] - 1, false)
                    }
                }
                3 -> {
                    answer[j] += m - (2 * shelves[j].cardinality())
                    shelves[j].flip(0, m)
                }
            }
        } else {
            val k = query[1]
            answer[j] = answer[k]
            last[j] = last[k].copyOf()
        }
    }
    println(answer.joinToString("\n").substring(2))
}