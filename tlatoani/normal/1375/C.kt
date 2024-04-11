import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val p = jin.readLine().split(" ").map { it.toInt() }
        out.appendln(if (p.first() < p.last()) "YES" else "NO")
    }
    print(out)
}