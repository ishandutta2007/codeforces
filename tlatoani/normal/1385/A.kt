import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (x, y, z) = jin.readLine().split(" ").map { it.toInt() }.sorted()
        if (y == z) {
            out.appendln("YES")
            out.appendln("$x $x $y")
        } else {
            out.appendln("NO")
        }
    }
    print(out)
}