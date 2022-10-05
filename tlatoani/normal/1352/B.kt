import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].toInt()
        if (k % 2 == 0 && n % 2 == 1 || (if (n % 2 == 0 && k % 2 == 1) n < 2 * k else n < k)) {
            out.appendln("NO")
        } else {
            out.appendln("YES")
            if (n % 2 == 0 && k % 2 == 1) {
                out.append(n - (2 * (k - 1)))
                for (j in 2..k) {
                    out.append(" 2")
                }
            } else {
                out.append(n - (k - 1))
                for (j in 2..k) {
                    out.append(" 1")
                }
            }
            out.appendln()
        }
    }
    print(out)
}