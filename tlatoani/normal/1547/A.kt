import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val (x, y) = readLine()!!.split(" ").map { it.toInt() }
        val (w, z) = readLine()!!.split(" ").map { it.toInt() }
        val (p, q) = readLine()!!.split(" ").map { it.toInt() }
        var answer = abs(w - x) + abs(z - y)
        if ((setOf(x, w, p).size == 1 && listOf(y, z, q).sorted()[1] == q) || (setOf(y, z, q).size == 1 && listOf(x, w, p).sorted()[1] == p)) {
            answer += 2
        }
        println(answer)
    }
}