import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val builder = StringBuilder()
    for (c in 1..jin.nextInt()) {
        //println("c = $c")
        val n = jin.nextInt()
        val prices = Array(n) { jin.nextLong() / 100L }
        prices.sortBy { p -> -p }
        val sums = LongArray((2 * n) + 1)
        for (i in 1..n) {
            sums[i] = sums[i - 1] + prices[i - 1]
        }
        for (i in n + 1..2 * n) {
            sums[i] = sums[i - 1]
        }
        //println("prices = ${prices.contentToString()}")
        //println("sums = ${sums.contentToString()}")
        val x = jin.nextLong()
        val a = jin.nextInt()
        val y = jin.nextLong()
        val b = jin.nextInt()
        val k = jin.nextLong()
        val lcmL = (a.toLong() * b.toLong()) / gcd(a.toLong(), b.toLong())
        val lcm = if (lcmL > n) n + 1 else lcmL.toInt()
        //println("lcm = $lcm")
        var foundAnswer = false
        for (i in 1..n) {
            val both = i / lcm
            val fora = (i / a) - both
            val forb = (i / b) - both
            val amount = if (x > y) {
                (sums[both] * (x + y)) + ((sums[fora + both] - sums[both]) * x) + ((sums[forb + fora + both] - sums[fora + both]) * y)
            } else {
                (sums[both] * (x + y)) + ((sums[forb + both] - sums[both]) * y) + ((sums[fora + forb + both] - sums[forb + both]) * x)
            }
            //println("i = $i, fora = $fora, forb = $forb, both = $both, amount = $amount")
            if (amount >= k) {
                builder.append(i)
                foundAnswer = true
                break
            }
        }
        if (!foundAnswer) {
            builder.append(-1)
        }
        builder.append('\n')
    }
    print(builder)
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