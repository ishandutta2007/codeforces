import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        var n = jin.readLine().toLong()
        while (n % 2L == 0L) {
            n /= 2L
        }
        out.appendln(if (n == 1L) "nO" else "yEs")
    }
    print(out)
}