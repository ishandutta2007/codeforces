import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = (listOf(0) + jin.readLine().split(" ").map { it.toInt() }).toIntArray()
        if (ay.sum() % n == 0) {
            var operationAMT = 0
            val operations = StringBuilder()
            fun perform(j: Int, k: Int, x: Int) {
                if (x != 0) {
                    operationAMT++
                    operations.appendln("$j $k $x")
                }
            }
            for (j in 2..n) {
                var x = (j - (ay[j] % j)) % j
                perform(1, j, x)
                ay[1] -= x
                ay[j] += x
                x = ay[j] / j
                perform(j, 1, x)
                ay[1] += ay[j]
                ay[j] = 0
            }
            val req = ay.sum() / n
            for (j in 2..n) {
                perform(1, j, req)
            }
            out.appendln(operationAMT)
            out.append(operations)
        } else {
            out.appendln(-1)
        }
    }
    print(out)
}