import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val ay = jin.readLine().split(" ").map { it.toInt() }
        if (k == 1) {
            out.appendln(if (ay.all { it == ay[0] }) 1 else -1)
        } else {
            out.appendln(max(1, (ay.toSet().size + k - 3) / (k - 1)))
        }
    }
    print(out)
}