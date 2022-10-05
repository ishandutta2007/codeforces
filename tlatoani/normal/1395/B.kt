import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    var (n, m, sy, sx) = jin.readLine().split(" ").map { it.toInt() }
    for (k in 1..n) {
        for (j in 1..m) {
            out.appendln("$sy $sx")
            if (j != m) {
                sx++
                if (sx == m + 1) {
                    sx = 1
                }
            }
        }
        sy++
        if (sy == n + 1) {
            sy = 1
        }
    }
    print(out)
}