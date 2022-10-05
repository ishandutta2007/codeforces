import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!
        var answer = n.length + 1
        for (d in 0..62) {
            val k = (1L shl d).toString()
            var j = 0
            for (digit in n) {
                if (j < k.length && digit == k[j]) {
                    j++
                }
            }
            answer = min(answer, n.length + k.length - (2 * j))
        }
        println(answer)
    }
}