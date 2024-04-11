import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    cases@for (c in 1..jin.readLine().toInt()) {
        var n = jin.readLine().toInt()
        while (n >= 0) {
            if (n % 2021 == 0) {
                out.appendln("yEs")
                continue@cases
            }
            n -= 2020
        }
        out.appendln("nO")
    }
    print(out)
}