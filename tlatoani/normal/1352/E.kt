import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }
        val disp = IntArray(n + 1)
        for (a in array) {
            disp[a]++
        }
        var answer = 0
        for (l in 1..n) {
            var curr = array[l - 1]
            for (r in l + 1..n) {
                curr += array[r - 1]
                if (curr > n) {
                    break
                }
                answer += disp[curr]
                disp[curr] = 0
            }
        }
        out.appendln(answer)
    }
    print(out)
}