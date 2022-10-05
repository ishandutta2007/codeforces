import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val weights = Array(n) { tokenizer.nextToken().toInt() }
    weights.sortDescending()
    weights[0]++
    for (j in 1 until n) {
        if (weights[j - 1] > weights[j] + 1) {
            weights[j]++
        } else if (weights[j - 1] <= weights[j] && weights[j - 1] > 1) {
            weights[j]--
        }
    }
    println(weights.toSet().size)
}