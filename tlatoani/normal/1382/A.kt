import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        jin.readLine()
        val ay = jin.readLine().split(" ").toSet()
        var found = false
        for (b in jin.readLine().split(" ")) {
            if (b in ay) {
                out.appendln("YES").append("1 ").appendln(b)
                found = true
                break
            }
        }
        if (!found) {
            out.appendln("NO")
        }
    }
    print(out)
}