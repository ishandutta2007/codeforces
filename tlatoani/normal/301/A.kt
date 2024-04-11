import kotlin.math.abs

fun main() {
    val n = readLine()!!.toInt()
    val ay = readLine()!!.split(" ").map { it.toInt() }
    if (n % 2 == 1 || ay.count { it < 0 } % 2 == 0) {
        println(ay.sumBy { abs(it) })
    } else {
        println(ay.sumBy { abs(it) } - (2 * ay.map { abs(it) }.min()!!))
    }
}