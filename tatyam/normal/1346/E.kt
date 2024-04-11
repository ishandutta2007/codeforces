import java.util.*
import kotlin.math.*

val scanner = Scanner(System.`in`)
val INF = 0x3fffffff


fun main() {
    val n = scanner.nextInt()
    val m = scanner.nextInt()
    val k = scanner.nextInt() - 1
    val cost = MutableList(n) { INF }
    cost[k] = 0
    for (i in 1..m) {
        val x = scanner.nextInt() - 1
        val y = scanner.nextInt() - 1
        Collections.swap(cost, x, y)
        cost[x] = min(cost[x], cost[y] + 1)
        cost[y] = min(cost[y], cost[x] + 1)
    }
    for (i in cost) print("${if (i == INF) -1 else i} ")
    println()
}