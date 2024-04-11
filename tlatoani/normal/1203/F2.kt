import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    var r = jin.nextInt()
    val projects = Array(n) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        Project(max(a, -b), b)
    }
    val pq = PriorityQueue<Project>(compareBy { it.a })
    pq.addAll(projects.filter { it.b >= 0 })
    var answer = 0
    while (pq.isNotEmpty() && pq.peek().a <= r) {
        r += pq.remove().b
        answer++
    }
    val dp = LongArray(r + 1)
    for (project in projects.sortedBy { it.a + it.b }) {
        if (project.b < 0) {
            for (k in r downTo project.a) {
                dp[k] = max(dp[k], dp[k + project.b] + 1)
            }
        }
    }
    println(answer + dp.max()!!)
}

data class Project(val a: Int, val b: Int)