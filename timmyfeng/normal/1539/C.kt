import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val args = reader.readLine().split(" ")
    val n = args[0].toInt()
    var k = args[1].toLong()
    val x = args[2].toLong()

    val a = reader.readLine().split(" ").map { it.toLong() }.sorted()
    val diff = LongArray(n - 1) { max(0, a[it + 1] - a[it] - 1) / x }.sorted()

    var ans = n
    for (i in diff) {
        if (i <= k) {
            k -= i
            --ans
        }
    }

    writer.println(ans)

    writer.close()
}