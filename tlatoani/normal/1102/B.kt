import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, k) = jin.readLine().split(" ").map { it.toInt() }
    val ay = jin.readLine().split(" ").map { it.toInt() }
    val freq = IntArray(5001)
    for (a in ay) {
        freq[a]++
    }
    if (freq.max()!! > k) {
        println("NO")
    } else {
        val ixs = (0 until n).sortedBy { ay[it] }
        val answer = IntArray(n)
        for (j in 0 until n) {
            answer[ixs[j]] = (j % k) + 1
        }
        println("YES")
        println(answer.joinToString(" "))
    }
}