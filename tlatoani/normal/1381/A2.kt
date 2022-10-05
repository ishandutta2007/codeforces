import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val a = jin.readLine()
        val b = jin.readLine()
        val answer = mutableListOf<Int>()
        for (j in 0 until n) {
            val k = if (j % 2 == 0) (j / 2) else (n - 1 - (j / 2))
            if ((a[k] == b[n - 1 - j]) == (j % 2 == 0)) {
                answer.add(1)
            }
            answer.add(n - j)
        }
        out.append(answer.size).append(' ').appendln(answer.joinToString(" "))
    }
    print(out)
}