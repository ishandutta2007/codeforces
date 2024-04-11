import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val t = reader.readLine().toInt()
    for (tt in 0 until t) {
        val (a, b, c) = reader.readLine().split(" ").map { it.toLong() }
        val d = c / b
        if (d >= a) {
            writer.println(a * (a - 1) / 2)
        } else {
            writer.println(d * a - d * (d + 1) / 2)
        }
    }

    writer.close()
}