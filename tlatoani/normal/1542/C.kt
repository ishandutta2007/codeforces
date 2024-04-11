const val MOD = 1000000007L

fun main() {
    var needed = 0L
    var l = 1L
    while (l <= 10000000000000000L) {
        needed++
        l = lcm(l, needed)
    }
    val lcms = LongArray(needed.toInt() + 2)
    lcms[1] = 1L
    for (k in 2..lcms.lastIndex) {
        lcms[k] = lcm(lcms[k - 1], k.toLong())
    }
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toLong()
        var answer = 0L
        for (k in 2..lcms.lastIndex) {
            answer += k.toLong() * (((n / lcms[k - 1]) - (n / lcms[k])) % MOD)
            answer %= MOD
        }
        println(answer)
    }
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)
fun lcm(a: Long, b: Long) = (a * b) / gcd(a, b)