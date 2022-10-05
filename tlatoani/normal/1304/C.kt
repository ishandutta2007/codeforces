import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val n = line.substring(0, six).toInt()
        var m = line.substring(six + 1).toLong()
        val customers = Array(n) {
            val tokenizer = StringTokenizer(readLine()!!)
            val t = tokenizer.nextToken().toLong()
            val l = tokenizer.nextToken().toLong()
            val h = tokenizer.nextToken().toLong()
            Customer(t, l, h)
        }
        customers.sortBy { it.t }
        var t = 0L
        var lower = m
        var upper = m
        var answer = true
        for (customer in customers) {
            val dt = customer.t - t
            lower -= dt
            upper += dt
            if (upper < customer.l || lower > customer.h) {
                answer = false
                break
            }
            lower = max(lower, customer.l)
            upper = min(upper, customer.h)
            t = customer.t
        }
        println(if (answer) "YES" else "NO")
    }
}

data class Customer(val t: Long, val l: Long, val h: Long)