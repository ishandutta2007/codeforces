import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val hs = jin.readLine().split(" ").map { it.toInt() }
        var minimo = hs[0]
        var mexico = hs[0]
        for (j in 1 until n) {
            minimo = max(minimo - (k - 1), hs[j])
            mexico = min(mexico + (k - 1), hs[j] + (k - 1))
            if (minimo > mexico) {
                out.appendln("nO")
                continue@cases
            }
        }
        out.appendln(if (hs[n - 1] in minimo..mexico) "yEs" else "nO")
    }
    print(out)
}