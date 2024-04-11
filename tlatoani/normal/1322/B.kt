import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val array = Array(n) { tokenizer.nextToken().toInt() }
    var answer = 0
    for (e in 0..24) {
        val b = 1 shl (e + 1)
        val b2 = 1 shl e
        val freq = IntArray(b)
        var amt = 0L
        for (a in array) {
            freq[a % b]++
            if ((a + a) % b >= b2) {
                amt--
            }
        }
        var total = 0L
        for (j in b2 until b) {
            total += freq[j]
        }
        for (j in 0 until b) {
            //println("b = $b, b2 = $b2, j = $j, total = $total")
            amt += freq[j].toLong() * total
            total += freq[(b2 - j - 1 + b) % b].toLong()
            total -= freq[(b - j - 1)].toLong()
        }
        amt /= 2L
        answer += (amt % 2L).toInt() * b2
    }
    println(answer)
}