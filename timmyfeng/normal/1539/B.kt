import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val (n, q) = reader.readLine().split(" ").map { it.toInt() }
    val s = reader.readLine()

    val sum = IntArray(n + 1)
    for (i in 0 until n) {
        sum[i + 1] = sum[i] + (s[i] - 'a') + 1
    }

    for (i in 0 until q) {
        val (l, r) = reader.readLine().split(" ").map { it.toInt() }
        writer.println(sum[r] - sum[l - 1])
    }

    writer.close()
}