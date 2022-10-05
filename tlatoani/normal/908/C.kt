import java.util.*
import kotlin.math.abs
import kotlin.math.max
import kotlin.math.sqrt

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val r = jin.nextInt()
    val xs = IntArray(n) { jin.nextInt() }
    val ys = DoubleArray(n) { r.toDouble() }
    for (j in 0 until n) {
        for (k in 0 until j) {
            if (abs(xs[j] - xs[k]) <= 2 * r) {
                ys[j] = max(ys[j], ys[k] + sqrt(((4 * r * r) - ((xs[j] - xs[k]) * (xs[j] - xs[k]))).toDouble()))
            }
        }
    }
    println(ys.joinToString(" "))
}