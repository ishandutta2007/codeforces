import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val m = 6 * n
    val who = BooleanArray(m + 1)
    val tokenizer = StringTokenizer(jin.readLine())
    for (j in 1..3 * n) {
        who[tokenizer.nextToken().toInt()] = true
    }
    val sums = IntArray(m + 1)
    for (j in 1..m) {
        sums[j] = sums[j - 1]
        if (who[j]) {
            sums[j]++
        }
    }
    val type = Array(m + 1) { IntArray(m + 2) }
    val midpoint = Array(m + 1) { IntArray(m + 2) }
    for (a in m downTo 1) {
        for (b in a + 2..m step 3) {
            if ((sums[b] - sums[a - 1]) % 3 == 0) {
                for (c in a until b) {
                    if (type[a][c] != 0 && type[c + 1][b] != 0) {
                        type[a][b] = 1
                        midpoint[a][b] = c
                        break
                    }
                }
                if (type[a][b] == 0 && who[a] == who[b]) {
                    for (c in a + 1 until b) {
                        if (who[c] == who[a] && (c == a + 1 || type[a + 1][c - 1] != 0) && (c == b - 1 || type[c + 1][b - 1] != 0)) {
                            type[a][b] = 2
                            midpoint[a][b] = c
                            break
                        }
                    }
                }
            }
        }
    }
    val q = LinkedList<Pair<Int, Int>>()
    val disp1 = LinkedList<Pair<Int, Int>>()
    val disp0 = LinkedList<Pair<Int, Int>>()
    val answer = mutableListOf<Triple<Int, Int, Int>>()
    q.add(Pair(1, m))
    for (x in 2 * n downTo 1) {
        while (q.isNotEmpty()) {
            val (a, b) = q.remove()
            if (type[a][b] == 1) {
                q.add(Pair(a, midpoint[a][b]))
                q.add(Pair(midpoint[a][b] + 1, b))
            } else {
                val d = (if (who[a]) disp1 else disp0)
                if (b == a + 2) {
                    d.addLast(Pair(a, b))
                } else {
                    d.addFirst(Pair(a, b))
                }
            }
        }
        val (a, b) = (if (x % 2 == 1) disp1 else disp0).remove()
        answer.add(Triple(a, midpoint[a][b], b))
        if (midpoint[a][b] != a + 1) {
            q.add(Pair(a + 1, midpoint[a][b] - 1))
        }
        if (midpoint[a][b] != b - 1) {
            q.add(Pair(midpoint[a][b] + 1, b - 1))
        }
    }
    println(answer.reversed().joinToString("\n") { "${it.first} ${it.second} ${it.third}"})
}