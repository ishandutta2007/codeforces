import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val s = jin.readLine()
        val sums0 = IntArray(s.length + 1)
        val sums1 = IntArray(s.length + 1)
        for (j in 1..s.length) {
            sums0[j] = sums0[j - 1]
            sums1[j] = sums1[j - 1]
            when (s[j - 1]) {
                '0' -> sums0[j]++
                '1' -> sums1[j]++
            }
        }
        println((1..s.length).map { min(sums0[it] + sums1[s.length] - sums1[it], sums1[it] + sums0[s.length] - sums0[it]) }.min())
    }
}