import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextInt()) {
        var r = jin.nextLong()
        var b = jin.nextLong()
        val k = jin.nextLong()
        var g = gcd(r, b)
        r /= g
        b /= g
        if (r > b) {
            val temp = r
            r = b
            b = temp
        }
        if (((b - 2L) / r) + 1L >= k) {
            println("REBEL")
        } else {
            println("OBEY")
        }
    }
}

fun gcd(a: Long, b: Long): Long {
    val max = max(a, b)
    val min = min(a, b)
    return if (min == 0L) {
        max
    } else {
        gcd(max % min, min)
    }
}