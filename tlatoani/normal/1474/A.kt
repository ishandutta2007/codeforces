import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val b = jin.readLine()
        var last = 0
        for (chara in b) {
            val d = chara - '0'
            last = if (d == 0) {
                if (last == 1) {
                    0
                } else {
                    1
                }
            } else {
                if (last == 2) {
                    1
                } else {
                    2
                }
            }
            out.append(last - d)
        }
        out.appendln()
    }
    print(out)
}