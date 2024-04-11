import kotlin.math.abs
import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        readLine()
        val ay = readLine()!!.split(" ").map { it.toInt() }.map { it % 2 }
        val answer = min(solve(ay), solve(ay.map { it + 1 }))
        println(if (answer == Long.MAX_VALUE) -1L else answer)
    }
}

fun solve(ay: List<Int>): Long {
    if (ay.count { it % 2 == 1 } != ay.size / 2) {
        return Long.MAX_VALUE
    }
    var amtOdd = 0L
    var answer = 0L
    for (x in ay) {
        if (x % 2 == 0) {
            answer += abs(amtOdd)
            amtOdd--
        } else {
            amtOdd++
        }
    }
    return answer
}