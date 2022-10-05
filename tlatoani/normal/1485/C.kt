import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(" ").map { it.toLong() }
        var answer = 0L
        for (b in 1L..min(200000L, y)) {
            answer += min(b - 1L, x / (b + 1L))
        }
        if (y > 200000L) {
            var prev = 200000L
            for (r in 5000L downTo 1L) {
                var upper = y
                var lower = prev
                while (upper > lower) {
                    val mid = (upper + lower + 1L) / 2L
                    if (r * (mid + 1L) <= x) {
                        lower = mid
                    } else {
                        upper = mid - 1L
                    }
                }
                answer += r * (upper - prev)
                prev = upper
            }
        }
        println(answer)
    }
}