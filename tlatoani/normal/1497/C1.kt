import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val m = n - (k - 3)
        val answer = mutableListOf<Int>()
        if (m % 4 == 0) {
            answer.add(m / 2)
            answer.add(m / 4)
            answer.add(m / 4)
        } else if (m % 2 == 0) {
            answer.add((m - 2) / 2)
            answer.add((m - 2) / 2)
            answer.add(2)
        } else {
            answer.add((m - 1) / 2)
            answer.add((m - 1) / 2)
            answer.add(1)
        }
        for (j in 1..k - 3) {
            answer.add(1)
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}