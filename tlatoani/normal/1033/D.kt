import kotlin.math.pow
import kotlin.math.roundToLong

const val MOD = 998244353L

fun main() {
    val n = readLine()!!.trim().toInt()
    val array = LongArray(n) { readLine()!!.trim().toLong() }
    val primes = mutableMapOf<Long, Long>()
    val composites = mutableMapOf<Long, Long>()
    for (k in array) {
        var root = k.toDouble().pow(.25).roundToLong()
        if (root * root * root * root == k) {
            primes[root] = (primes[root] ?: 0L) + 4L
        } else {
            root = k.toDouble().pow(1.0 / 3.0).roundToLong()
            if (root * root * root == k) {
                primes[root] = (primes[root] ?: 0L) + 3L
            } else {
                root = k.toDouble().pow(.5).roundToLong()
                if (root * root == k) {
                    primes[root] = (primes[root] ?: 0L) + 2L
                } else {
                    var p = 0L
                    for (k2 in array) {
                        p = gcd(k, k2)
                        if (p != 1L && p != k) {
                            break
                        }
                    }
                    if (p == 1L || p == k) {
                        composites[k] = (composites[k] ?: 0L) + 1L
                    } else {
                        val q = k / p
                        primes[p] = (primes[p] ?: 0L) + 1L
                        primes[q] = (primes[q] ?: 0L) + 1L
                    }
                }
            }
        }
    }
    var answer = 1L
    for (f in primes.values) {
        answer *= f + 1L
        answer %= MOD
    }
    for (f in composites.values) {
        answer *= f + 1L
        answer *= f + 1L
        answer %= MOD
    }
    println(answer)
}

fun gcd(a: Long, b: Long): Long {
    if (b == 0L) {
        return a
    } else {
        return gcd(b, a % b)
    }
}