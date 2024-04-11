import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    var k = jin.nextLong()
    var answer: Long = 0
    val days = Array(n) {
        val a = jin.nextLong()
        val b = jin.nextLong()
        val price = jin.nextLong()
        k -= a
        answer += a * price
        Day(price, b - a)
    }
    days.sortBy { it.price }
    for (day in days) {
        if (k <= 0L) {
            break
        }
        val amt = min(day.max, k)
        k -= amt
        answer += amt * day.price
    }
    if (k == 0L) {
        println(answer)
    } else {
        println(-1)
    }
}

data class Day(val price: Long, val max: Long)