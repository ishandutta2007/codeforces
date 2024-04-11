import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }
        val by = jin.readLine().split(" ").map { it.toInt() }
        val cy = jin.readLine().split(" ").map { it.toInt() }
        val answer = mutableListOf<Int>()
        answer.add(ay[0])
        for (j in 1..n - 2) {
            if (ay[j] != answer.last()) {
                answer.add(ay[j])
            } else {
                answer.add(by[j])
            }
        }
        if (ay[n - 1] != answer.last() && ay[n - 1] != answer[0]) {
            answer.add(ay[n - 1])
        } else if (by[n - 1] != answer.last() && by[n - 1] != answer[0]) {
            answer.add(by[n - 1])
        } else {
            answer.add(cy[n - 1])
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}