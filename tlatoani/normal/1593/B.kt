import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!
        var answer = n.length
        for (pos in listOf("25", "50", "75", "00")) {
            val j = n.lastIndexOf(pos[1])
            if (j != -1) {
                val k = n.substring(0, j).lastIndexOf(pos[0])
                if (k != -1) {
                    answer = min(answer, n.length - k - 2)
                }
            }
        }
        println(answer)
    }
}