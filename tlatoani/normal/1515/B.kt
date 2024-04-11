import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val squares = (1..31622).map { it * it }.toSet()
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        out.appendln(if ((n % 2 == 0 && n / 2 in squares) || (n % 4 == 0 && n / 4 in squares)) "YES" else "NO")
    }
    print(out)
}