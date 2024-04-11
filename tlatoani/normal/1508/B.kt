import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        var k = line[1].toLong()
        if (n < 63 && k > 1L shl max(0, n - 1)) {
            out.appendln(-1)
        } else {
            var j = 1
            while (j <= n) {
                if (n - j >= 63 || k <= 1L shl max(0, n - j - 1)) {
                    out.append(j).append(' ')
                    j++
                } else {
                    for (j2 in j..n) {
                        if (k <= 1L shl max(0, n - j2 - 1)) {
                            for (j3 in j2 downTo j) {
                                out.append(j3).append(' ')
                            }
                            j = j2 + 1
                        } else {
                            k -= 1L shl (n - j2 - 1)
                        }
                    }
                }
            }
            out.appendln()
        }
    }
    print(out)
}