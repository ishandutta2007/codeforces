import java.util.*
import kotlin.math.abs
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val x = LongArray(100)
    val y = LongArray(100)
    x[0] = jin.nextLong()
    y[0] = jin.nextLong()
    val ax = jin.nextLong()
    val ay = jin.nextLong()
    val bx = jin.nextLong()
    val by = jin.nextLong()
    val xs = jin.nextLong()
    val ys = jin.nextLong()
    val t = jin.nextLong()
    var j = 1
    while (true) {
        x[j] = (ax * x[j - 1]) + bx
        y[j] = (ay * y[j - 1]) + by
        if (x[j] + y[j] >= 30000000000000000) {
            break
        }
        j++
    }
    var answer = 0
    for (k1 in 0..j) {
        for (k2 in 0..j) {
            val d = (abs(xs - x[k1]) + abs(ys - y[k1])) + (abs(x[k2] - x[k1]) + abs(y[k2] - y[k1]))
            if (d <= t) {
                answer = max(answer, abs(k1 - k2) + 1)
            }
        }
    }
    println(answer)
}