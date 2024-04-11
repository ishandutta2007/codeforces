import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, k) = jin.readLine().split(" ").map { it.toInt() }
        val answer = Array(n) { CharArray(n) { '0' } }
        for (j in 0 until k) {
            answer[j % n][((j % n) + (j / n)) % n] = '1'
        }
        out.appendln(if (k % n == 0) 0 else 2)
        answer.forEach { out.appendln(it) }
    }
    print(out)
}