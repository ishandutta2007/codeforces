import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }.toIntArray()
        val locked = jin.readLine().split(" ").map { it == "1" }
        var sum = ay.sum()
        for (k in n - 1 downTo 0) {
            if (sum < 0) {
                break
            }
            if (locked[k]) {
                sum -= ay[k]
            } else {
                var m = k
                for (j in 0..k) {
                    if (!locked[j] && ay[j] < ay[m]) {
                        m = j
                    }
                }
                val temp = ay[k]
                ay[k] = ay[m]
                ay[m] = temp
                sum -= ay[k]
            }
        }
        out.appendln(ay.joinToString(" "))
    }
    print(out)
}