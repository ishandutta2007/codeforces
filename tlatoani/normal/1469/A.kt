import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        out.appendln(if (s.length % 2 == 0 && s[0] != ')' && s.last() != '(') "yEs" else "nO")
    }
    print(out)
}