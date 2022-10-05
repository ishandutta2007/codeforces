import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val s = jin.readLine()
        var answer = true
        var amt0 = 0
        var amt1 = 0
        var amtDisp = 0
        for (r in 0 until k) {
            var is0 = false
            var is1 = false
            var j = r
            while (j < n) {
                when (s[j]) {
                    '0' -> is0 = true
                    '1' -> is1 = true
                }
                j += k
            }
            if (is0) {
                if (is1) {
                    answer = false
                } else {
                    amt0++
                }
            } else {
                if (is1) {
                    amt1++
                } else {
                    amtDisp++
                }
            }
        }
        answer = answer && abs(amt1 - amt0) <= amtDisp
        out.appendln(if (answer) "YES" else "NO")
    }
    print(out)
}