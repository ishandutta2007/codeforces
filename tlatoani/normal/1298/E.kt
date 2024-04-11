import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toInt()
    tokenizer = StringTokenizer(readLine()!!)
    val antiskill = IntArray(n) { tokenizer.nextToken().toInt() }
    val answer = IntArray(n)
    for (j in 1..k) {
        tokenizer = StringTokenizer(readLine()!!)
        val a = tokenizer.nextToken().toInt() - 1
        val b = tokenizer.nextToken().toInt() - 1
        if (antiskill[a] > antiskill[b]) {
            answer[a]--
        } else if (antiskill[b] > antiskill[a]) {
            answer[b]--
        }
    }
    val programmers = Array(n) { it }
    programmers.sortBy { antiskill[it] }
    var j2 = 0
    for (j1 in 0 until n) {
        while (antiskill[programmers[j2]] < antiskill[programmers[j1]]) {
            j2++
        }
        answer[programmers[j1]] += j2
    }
    println(answer.joinToString(" "))
}