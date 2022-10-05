import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val freq = IntArray(n + 1)
        val ay = jin.readLine().split(" ").map { it.toInt() }
        for (a in ay) {
            freq[a]++
        }
        if (freq.max()!! > (n + 1) / 2) {
            out.appendln(-1)
        } else {
            freq.fill(0)
            freq[ay[0]]++
            freq[ay.last()]++
            for (j in 1 until n) {
                if (ay[j - 1] == ay[j]) {
                    freq[ay[j]] += 2
                }
            }
            out.appendln(max(freq.max()!! - 2, (freq.sum() / 2) - 1))
        }
    }
    print(out)
}