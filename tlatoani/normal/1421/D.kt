import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val (x, y) = jin.readLine().split(" ").map { it.toLong() }
        val costs = jin.readLine().split(" ").map { it.toLong() }.toLongArray()
        for (j in 0..5) {
            costs[j] = min(costs[j], costs[(j + 1) % 6] + costs[(j + 5) % 6])
        }
        var answer = max(y * costs[1], -y * costs[4]) + max(x * costs[5], -x * costs[2])
        answer = min(answer, max(x * costs[0], -x * costs[3]) + max((y - x) * costs[1], (x - y) * costs[4]))
        answer = min(answer, max((x - y) * costs[5], (y - x) * costs[2]) + max(y * costs[0], -y * costs[3]))
        println(answer)
    }
}