import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var tokenizer = StringTokenizer(jin.readLine())
    tokenizer.nextToken()
    val m = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(jin.readLine())
    val islands = Array(m) { tokenizer.nextToken().toInt() }
    islands.sort()
    tokenizer = StringTokenizer(jin.readLine())
    val g = tokenizer.nextToken().toInt()
    val r = tokenizer.nextToken().toInt()
    var q = LinkedList<Int>()
    var qAlt = LinkedList<Int>()
    val seen = Array(m) { BooleanArray(g) }
    seen[0][0] = true
    q.add(0)
    q.add(0)
    for (j in 0..m) {
        if (q.isEmpty()) {
            break
        }
        var answer = 1150
        while (q.isNotEmpty()) {
            val a = q.remove()
            val t = q.remove()
            if (a == m - 1) {
                answer = min(answer, t)
            }
            if (a > 0) {
                if (t + islands[a] - islands[a - 1] < g && !seen[a - 1][t + islands[a] - islands[a - 1]]) {
                    seen[a - 1][t + islands[a] - islands[a - 1]] = true
                    q.add(a - 1)
                    q.add(t + islands[a] - islands[a - 1])
                }
                if (t + islands[a] - islands[a - 1] == g && !seen[a - 1][0]) {
                    seen[a - 1][0] = true
                    qAlt.add(a - 1)
                    qAlt.add(0)
                }
            }
            if (a < m - 1) {
                if (t + islands[a + 1] - islands[a] < g && !seen[a + 1][t + islands[a + 1] - islands[a]]) {
                    seen[a + 1][t + islands[a + 1] - islands[a]] = true
                    q.add(a + 1)
                    q.add(t + islands[a + 1] - islands[a])
                }
                if (t + islands[a + 1] - islands[a] == g && !seen[a + 1][0]) {
                    seen[a + 1][0] = true
                    qAlt.add(a + 1)
                    qAlt.add(0)
                }
            }
        }
        if (answer == 0) {
            println(((g + r) * j) - r)
            return
        } else if (answer < g) {
            println(((g + r) * j) + answer)
            return
        }
        val temp = q
        q = qAlt
        qAlt = temp
    }
    println(-1)
}