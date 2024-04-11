import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }
        var j = n - 2
        while (j >= 0 && ay[j] >= ay[j + 1]) {
            j--
        }
        j--
        while (j >= 0 && ay[j] <= ay[j + 1]) {
            j--
        }
        j = max(-1, j)
        out.appendln(j + 1)
    }
    print(out)
}