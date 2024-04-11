import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    var g = 0L
    for (j in 1..n) {
        g = gcd(tokenizer.nextToken().toLong(), g)
    }
    var answer = 1
    for (p in 2L..1000000L) {
        var e = 1
        while (g % p == 0L) {
            g /= p
            e++
        }
        answer *= e
    }
    if (g != 1L) {
        answer *= 2
    }
    println(answer)
}

fun gcd(a: Long, b: Long): Long {
    return if (b == 0L) {
        a
    } else gcd(b, a % b)
}