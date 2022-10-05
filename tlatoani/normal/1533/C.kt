import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        val s = readLine()!!
        var amtLiked = s.count { it == '1' }
        val sweets = LinkedList<Boolean>()
        sweets.addAll(s.map { it == '1' })
        var answer = 0
        while (amtLiked > 0) {
            answer++
            if (sweets.removeFirst()) {
                amtLiked--
            }
            if (amtLiked == 0) {
                break
            }
            repeat(k - 1) {
                sweets.addLast(sweets.removeFirst())
            }
        }
        println(answer)
    }
}