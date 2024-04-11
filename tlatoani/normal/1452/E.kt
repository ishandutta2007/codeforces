import kotlin.math.max
import kotlin.math.min

fun main() {
    val (n, m, k) = readLine()!!.split(" ").map { it.toInt() }
    val participants = Array(m) { readLine()!!.split(" ").map { it.toInt() } }
    var answer = 0
    val deltas = IntArray(3001)
    for (a1 in 1..n - k + 1) {
        val b1 = a1 + k - 1
        var curr = 0
        deltas.fill(0)
        for ((l, r) in participants) {
            val x = max(0, min(b1, r) - max(a1, l) + 1)
            curr += x
            deltas[max(1, l - k + 1)]++
            if (r - l + 1 <= k) {
                deltas[max(1, r - k + 2)]--
                deltas[l + 1]--
            } else {
                deltas[l + 1]--
                deltas[r - k + 2]--
            }
            deltas[r - x + 2]++
        }
        answer = max(answer, curr)
        var change = 0
        for (a2 in 1..a1) {
            change += deltas[a2]
        }
        for (a2 in a1 + 1..n - k + 1) {
            change += deltas[a2]
            curr += change
            answer = max(answer, curr)
        }
    }
    println(answer)
}