import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val lcps = jin.readLine().split(" ").map { it.toInt() }
        var last = "a".repeat(51).toCharArray()
        out.appendln(last)
        for (lcp in lcps) {
            last[lcp] = ('a'.toInt() + 'b'.toInt() - last[lcp].toInt()).toChar()
            out.appendln(last)
        }
    }
    print(out)
}