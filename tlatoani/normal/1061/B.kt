import java.util.*

fun main() {
    var tokenizer = StringTokenizer(readLine()!!)
    val n = tokenizer.nextToken().toInt()
    val m = tokenizer.nextToken().toLong()
    tokenizer = StringTokenizer(readLine()!!)
    val heights = Array(n) { tokenizer.nextToken().toLong() }
    heights.sortDescending()
    var answer = heights.sum() - n.toLong()
    var k = heights[0]
    for (h in heights) {
        if (k > h) {
            answer -= k - h
            k = h
        }
        k--
    }
    if (k > 0L) {
        answer -= k
    }
    println(answer)
}