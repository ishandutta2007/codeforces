import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (j in 1..jin.readLine().toInt()) {
        val b = jin.readLine()
        for (j in 0 until b.length / 2) {
            out.append(b[2 * j])
        }
        out.appendln(b.last())
    }
    print(out)
}