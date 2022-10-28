import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    var t = reader.readLine().toInt()
    while (t-- > 0) {
        val (n, k) = reader.readLine().split(" ").map { it.toInt() }
        var ans = 0
        for (i in 0 until n) {
            val (l, r) = reader.readLine().split(" ").map { it.toInt() }
            if (l <= k) {
                ans = max(ans, r - k + 1)
            }
        }
        writer.println(ans)
    }

    writer.close()
}