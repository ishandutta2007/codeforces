import kotlin.math.*
import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val n = reader.readLine().toInt()
    val a = reader.readLine().split(" ").map { it.toInt() }.shuffled().sorted()
    val b = reader.readLine().split(" ").map { it.toInt() }.shuffled().sorted()

    val prefix = IntArray(n + 1) { Int.MIN_VALUE }
    for (i in 0 until n) {
        prefix[i + 1] = max(prefix[i], b[i] - a[i])
    }

    val suffix = IntArray(n + 1) { Int.MIN_VALUE }
    for (i in n - 1 downTo 0) {
        suffix[i] = max(suffix[i + 1], b[i + 1] - a[i])
    }

    val m = reader.readLine().toInt()
    val c = reader.readLine().split(" ").map { it.toInt() }

    for (i in c) {
        var low = 0
        var high = n
        while (low < high) {
            val mid = (low + high) / 2
            if (a[mid] < i) {
                low = mid + 1
            } else {
                high = mid
            }
        }

        writer.print("${max(b[low] - i, max(prefix[low], suffix[low]))} ")
    }
    writer.println()

    writer.close()
}