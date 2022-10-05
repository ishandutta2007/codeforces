import kotlin.math.max
import kotlin.math.min

fun main() {
    val n = readLine()!!.toInt()
    val ay = readLine()!!.split(" ").map { it.toInt() }
    val by = readLine()!!.split(" ").map { it.toInt() }
    println(max(0, (0..2).map { ay[it] + by[(it + 1) % 3] }.max()!! - n))
    println((0..2).sumBy { min(ay[it], by[(it + 1) % 3]) })
}