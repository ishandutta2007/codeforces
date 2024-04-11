import java.util.*

const val MOD = 998244353L

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(readLine()!!)
    val p = IntArray(n) { tokenizer.nextToken().toInt() }
    var answer1 = 0L
    for (j in n - k + 1..n) {
        answer1 += j.toLong()
    }
    var answer2 = 1L
    var j1 = 0
    while (p[j1] < n - k + 1) {
        j1++
    }
    for (j2 in j1 + 1 until n) {
        if (p[j2] >= n - k + 1) {
            answer2 *= (j2 - j1).toLong()
            answer2 %= MOD
            j1 = j2
        }
    }
    println("$answer1 $answer2")
}