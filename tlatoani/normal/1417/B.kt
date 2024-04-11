import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (j in 1..jin.readLine().toInt()) {
        val (n, t) = jin.readLine().split(" ").map { it.toInt() }
        var parity = true
        for (a in jin.readLine().split(" ").map { it.toInt() }) {
            if (2 * a < t) {
                out.append("0 ")
            } else if (2 * a == t) {
                if (parity) {
                    out.append("0 ")
                } else {
                    out.append("1 ")
                }
                parity = !parity
            } else {
                out.append("1 ")
            }
        }
        out.appendln()
    }
    print(out)
}