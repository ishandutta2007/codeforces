import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val k = readLine()!!.toLong()
        var upper = k
        var lower = 0L
        while (upper > lower) {
            val mid = (upper + lower + 1L) / 2L
            if (mid * mid < k) {
                lower = mid
            } else {
                upper = mid - 1L
            }
        }
        val s = upper
        val y = min(s + 1L, k - (s * s))
        val x = min(s + 1L, ((s + 1L) * (s + 1L)) - k + 1L)
        println("$y $x")
    }
}