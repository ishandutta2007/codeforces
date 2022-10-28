import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val (health, n) = reader.readLine().split(" ").map { it.toLong() }
    val damage = reader.readLine().split(" ").map {it.toLong() }

    val sum = -damage.sum()
    var ans = Long.MAX_VALUE
    var prefix = 0L

    for (i in 0 until n) {
        if (health + prefix <= 0) {
            ans = min(ans, i)
        } else if (sum > 0) {
            ans = min(ans, (health + prefix + sum - 1) / sum * n + i)
        }
        prefix += damage[i.toInt()]
    }

    writer.println(if (ans == Long.MAX_VALUE) -1 else ans)

    writer.close()
}