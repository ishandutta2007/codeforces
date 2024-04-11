import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val cake = readLine()!!.split(" ").map { it.toInt() }
        var answer = 0
        for (j in cake.indices) {
            for (k in cake.indices) {
                if (j != k) {
                    answer = max(answer, cake[j] + cake[k])
                }
            }
        }
        println(answer)
    }
}