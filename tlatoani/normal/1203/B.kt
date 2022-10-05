import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val lengths = LinkedList<Int>()
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..4 * n) {
            lengths.add(tokenizer.nextToken().toInt())
        }
        lengths.sort()
        var answer = true
        val area = lengths[0] * lengths.last
        while (lengths.isNotEmpty()) {
            if (lengths[0] != lengths[1]) {
                answer = false
                break
            }
            if (lengths.last != lengths[lengths.size - 2]) {
                answer = false
                break
            }
            if (lengths[0] * lengths.last != area) {
                answer = false
                break
            }
            lengths.removeFirst()
            lengths.removeFirst()
            lengths.removeLast()
            lengths.removeLast()
        }
        println(if (answer) "YES" else "NO")
    }
}