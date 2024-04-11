import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val s = jin.readLine()
        var last = if (s[0] == 'L') 'R' else 'L'
        var curr = 0
        val answer = IntArray(n + 1) { 1 }
        for (j in 0 until n) {
            curr++
            val dir = s[j]
            if (dir == last) {
                if (dir == 'L') {
                    answer[j] = curr
                }
                for (k in j - 1 downTo 0) {
                    if (s[k] == 'R') {
                        answer[k] = max(answer[k], curr)
                    }
                    if (k == 0 || s[k - 1] == s[k]) {
                        break
                    }
                }
                curr = 1
            } else {
                last = dir
            }
        }
        curr++
        if (last == 'L') {
            answer[n] = curr
        }
        for (k in n - 1 downTo 0) {
            if (s[k] == 'R') {
                answer[k] = max(answer[k], curr)
            }
            if (k == 0 || s[k - 1] == s[k]) {
                break
            }
        }
        out.appendln(answer.joinToString(" "))
    }
    print(out)
}