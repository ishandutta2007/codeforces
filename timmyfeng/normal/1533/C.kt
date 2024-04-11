import java.io.*

fun main() {
    val reader = System.`in`.bufferedReader()
    val writer = PrintWriter(System.out, false)

    var t = reader.readLine().toInt()
    while (t-- > 0) {
        val (n, k) = reader.readLine().split(" ").map { it.toInt() }
        val s = reader.readLine()

        var like = s.count { it == '1' }
        val sweets = MutableList(n) { it }
        var ptr = n - k + 1

        while (like > 0) {
            ptr = (ptr + k - 1) % sweets.size
            if (s[sweets[ptr]] == '1') {
                --like
            }
            sweets.removeAt(ptr)
        }

        writer.println(n - sweets.size)
    }

    writer.close()
}