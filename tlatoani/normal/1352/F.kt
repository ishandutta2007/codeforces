import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().split(" ").map { it.toInt() }
        if (n[1] == 0) {
            if (n[2] == 0) {
                out.appendln("0".repeat(n[0] + 1))
            } else {
                out.appendln("1".repeat(n[2] + 1))
            }
        } else {
            if (n[1] % 2 == 0) {
                out.append('1')
            }
            out.append("0".repeat(n[0] + 1))
            out.append("10".repeat((n[1] - 1) / 2))
            out.appendln("1".repeat(n[2] + 1))
        }
    }
    print(out)
}