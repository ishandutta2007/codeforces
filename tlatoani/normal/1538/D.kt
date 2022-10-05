fun main() {
    val isPrime = BooleanArray(32001) { true }
    for (p in 2..32000) {
        if (isPrime[p]) {
            for (k in 2 * p..32000 step p) {
                isPrime[k] = false
            }
        }
    }
    val primes = (2..32000).filter { isPrime[it] }
    repeat(readLine()!!.toInt()) {
        var (a, b, k) = readLine()!!.split(" ").map { it.toInt() }
        if (a == b && k == 1) {
            println("nO")
        } else {
            val min = when {
                a == b -> 0
                a % b == 0 -> 1
                b % a == 0 -> 1
                else -> 2
            }
            var max = 0
            for (p in primes) {
                while (a % p == 0) {
                    a /= p
                    max++
                }
                while (b % p == 0) {
                    b /= p
                    max++
                }
            }
            if (a > 1) {
                max++
            }
            if (b > 1) {
                max++
            }
            println(if (k in min..max) "yEs" else "nO")
        }
    }
}