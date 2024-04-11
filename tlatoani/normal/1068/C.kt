import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val n = line[0].toInt()
    val m = line[1].toInt()
    val answer = Array(n + 1) { mutableListOf(it) }
    for (j in n + 1..n + m) {
        val line = jin.readLine().split(" ")
        answer[line[0].toInt()].add(j)
        answer[line[1].toInt()].add(j)
    }
    val out = StringBuilder()
    for (j in 1..n) {
        out.appendln(answer[j].size)
        for (x in answer[j]) {
            out.append(x).append(' ').appendln(j)
        }
    }
    print(out)
}