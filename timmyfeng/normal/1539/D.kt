import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val n = reader.readLine().toInt()

    var total = 0L
    val products = mutableListOf<Pair<Long, Long>>()
    for (i in 0 until n) {
        val (a, b) = reader.readLine().split(" ").map { it.toLong() }
        products.add(b to a)
        total += a
    }
    products.sortBy { it.first }

    var ans = 2 * total
    var have = 0L
    for ((b, a) in products) {
        have = max(have, min(total, b))
        val save = min(total - have, a)
        have += save
        ans -= save
    }

    writer.println(ans)

    writer.close()
}