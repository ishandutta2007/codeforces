import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val seen = BooleanArray(s.length + 1)
        var answer = s.length.toLong()
        var curr = 0
        for (j in 1..s.length) {
            curr += (if (s[j - 1] == '+') 1 else -1)
            if (curr < 0 && !seen[-curr]) {
                answer += j.toLong()
                seen[-curr] = true
            }
        }
        println(answer)
    }
}