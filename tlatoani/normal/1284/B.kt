import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val nl = n.toLong()
    var already = 0L
    val above = mutableListOf<Int>()
    val below = mutableListOf<Int>()
    for (j in 1..n) {
        val tokenizer = StringTokenizer(readLine()!!)
        val l = tokenizer.nextToken().toInt()
        val seq = IntArray(l) { tokenizer.nextToken().toInt() }
        var minSoFar = Int.MAX_VALUE
        var hasAscent = false
        for (s in seq) {
            if (s > minSoFar) {
                hasAscent = true
                break
            }
            minSoFar = s
        }
        if (hasAscent) {
            already++
        } else {
            above.add(seq.max()!!)
            below.add(seq.min()!!)
        }
    }
    above.sortDescending()
    below.sortDescending()
    var answer = (nl * nl) - ((nl - already) * (nl - already))
    var k = 0
    for (j in 0 until above.size) {
        while (k < below.size && above[j] <= below[k]) {
            k++
        }
        answer += (below.size - k).toLong()
    }
    println(answer)
}