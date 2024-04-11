import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    val (n, m) = reader.readLine().split(" ").map { it.toInt() }

    val start = mutableSetOf<String>()
    for (i in 0 until n) {
        start.add(reader.readLine())
    }

    val q = reader.readLine().toInt()
    for (i in 0 until q) {
        val t = reader.readLine()

        val end = mutableSetOf<String>()
        for (j in 0..m) {
            end.add(t.substring(0, j) + t.substring(j + 1, m + 1))
        }

        var ans = 0
        for (j in end) {
            if (j in start) {
                ++ans
            }
        }

        writer.println(ans)
    }

    writer.close()
}