import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toLong()
        val tokenizer = StringTokenizer(readLine()!!)
        var answer = "yEs"
        var lcm = 1L
        for (k in 2L..n + 1L) {
            if (lcm <= 1000000000L) {
                lcm = lcm(lcm, k)
            }
            val x = tokenizer.nextToken().toLong()
            if (x % lcm == 0L) {
                answer = "nO"
            }
        }
        println(answer)
    }
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
fun lcm(a: Long, b: Long) = (a * b) / gcd(a, b)