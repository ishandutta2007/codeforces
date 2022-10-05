import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val ay = jin.readLine().split(" ").map { it.toInt() }
        val occs = Array(n + 1) { mutableListOf<Int>() }
        for (j in 0 until n) {
            occs[ay[j]].add(j)
        }
        var j = 1
        var from = 0
        var to = n - 1
        while (j <= n && occs[j].size == 1 && (occs[j][0] == from || occs[j][0] == to)) {
            if (occs[j][0] == from) {
                from++
            } else {
                to--
            }
            j++
        }
        if (j <= n && occs[j].isNotEmpty()) {
            j++
        }
        val answer = CharArray(n + 1) { if (it >= n + 2 - j) '1' else '0' }
        if ((1..n).all { occs[it].isNotEmpty() }) {
            answer[1] = '1'
        }
        out.appendln(String(answer).substring(1))
    }
    print(out)
}