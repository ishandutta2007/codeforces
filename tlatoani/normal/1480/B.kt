import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        val (ah, bh, n) = jin.readLine().split(" ").map { it.toLong() }
        val ay = jin.readLine().split(" ").map { it.toLong() }
        val by = jin.readLine().split(" ").map { it.toLong() }
        var damage = 0L
        for (j in 0 until n.toInt()) {
            damage += ((by[j] + ah - 1L) / ah) * ay[j]
            if (damage >= 2000000000L) {
                out.appendln("NO")
                continue@cases
            }
        }
        for (j in 0 until n.toInt()) {
            if (bh > damage - ay[j]) {
                out.appendln("YES")
                continue@cases
            }
        }
        out.appendln("NO")
    }
    print(out)
}