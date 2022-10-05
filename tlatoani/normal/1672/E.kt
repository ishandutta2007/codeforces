import kotlin.math.min

fun main() {
    val n = readLine()!!.toLong()
    var answer = 4000000L + n
    fun query(width: Long): Long {
        println("? $width")
        val height = readLine()!!.toLong()
        if (height != 0L) {
            answer = min(answer, width * height)
        }
        return height
    }
    var upper = 4000000L + n
    var lower = n
    while (upper > lower) {
        val mid = (upper + lower) / 2L
        if (query(mid) == 1L) {
            upper = mid
        } else {
            lower = mid + 1L
        }
    }
    val totalLength = upper
    for (h in 1L..n) {
        query(totalLength / h)
    }
    println("! $answer")
}