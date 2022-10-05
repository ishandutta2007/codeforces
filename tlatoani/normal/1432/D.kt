import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, a, b) = jin.readLine().split(" ").map { it.toInt() }
        for (j in 0 until b) {
            out.append('a' + j)
        }
        for (j in b until a) {
            out.append('a')
        }
        for (j in a until n) {
            out.append(out[out.length - a])
        }
        out.appendln()
    }
    print(out)
}