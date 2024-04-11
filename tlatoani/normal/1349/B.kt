import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }
        if (k !in array) {
            out.appendln("nO")
            continue
        }
        var answer = n == 1
        for (j in 1 until n) {
            if (array[j - 1] >= k && array[j] >= k) {
                answer = true
            }
        }
        for (j in 1 until n - 1) {
            if (array[j - 1] >= k && array[j + 1] >= k) {
                answer = true
            }
        }
        out.appendln(if (answer) "yEs" else "nO")
    }
    print(out)
}