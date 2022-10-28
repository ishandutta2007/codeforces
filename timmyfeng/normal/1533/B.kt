import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    var t = reader.readLine().toInt()
    while (t-- > 0) {
        val n = reader.readLine().toInt()
        val a = reader.readLine().split(" ").map { it.toInt() }
        var ans = false
        for (i in 1 until n) {
            if ((a[i] - a[i - 1]) % 2 == 0) {
                ans = true
            }
        }
        writer.println(if (ans) "YES" else "NO")
    }

    writer.close()
}