import java.util.*
import java.io.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        out.append(9)
        for (j in 0..n - 2) {
            out.append((8 + j) % 10)
        }
        out.appendln()
    }
    print(out)
}