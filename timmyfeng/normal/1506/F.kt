import java.io.*
import java.util.*
import kotlin.math.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    for (t in 0 until reader.readLine().toInt()) {
        val n = reader.readLine().toInt()
        val r = reader.readLine().split(" ").map { it.toInt() }
        val c = reader.readLine().split(" ").map { it.toInt() }

        val points = Array(n) { r[it] to c[it] }
        points.sortBy { it.first }

        var ans = 0
        var x = 1
        var y = 1

        for ((a, b) in points) {
            if (x == a && y == b) {
                continue
            }

            val down = (a - x) - (b - y)
            ans += if (down == 0 && (x + y) % 2 == 0) {
                a - x
            } else {
                (down + (x + y) % 2) / 2
            }

            x = a
            y = b
        }

        writer.println(ans)
    }

    writer.close()
}