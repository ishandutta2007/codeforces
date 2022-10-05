import java.util.*
import kotlin.math.abs

fun main() {
    val jin = Scanner(System.`in`)
    val lastPrime = IntArray(100001) { 1 }
    for (p in 2..100000) {
        if (lastPrime[p] == 1) {
            var k = p
            while (k <= 100000) {
                lastPrime[k] = p
                k += p
            }
        }
    }
    val divisors = Array(100001) { mutableListOf<Int>() }
    divisors[1].add(1)
    for (k in 2..100000) {
        val p = lastPrime[k]
        val prev = divisors[k / p]
        for (j in prev.indices) {
            if (j == 0 || prev[j - 1] * p != prev[j]) {
                divisors[k].add(prev[j])
            }
            divisors[k].add(prev[j] * p)
        }
    }
    for (c in 1..jin.nextInt()) {
        val a = jin.nextInt()
        val b = jin.nextInt()
        val c = jin.nextInt()
        var res = a + b + c
        var sol = Solution(0, 0, 0)
        for (beta in 1..20000) {
            var alpha = 1
            for (divisor in divisors[beta]) {
                if (abs(divisor - a) < abs(alpha - a)) {
                    alpha = divisor
                }
            }
            var gamma = (c / beta) * beta
            if (abs(gamma + beta - c) < abs(gamma - c) || gamma == 0) {
                gamma += beta
            }
            val pos = abs(alpha - a) + abs(beta - b) + abs(gamma - c)
            if (pos < res) {
                res = pos
                sol = Solution(alpha, beta, gamma)
            }
        }
        println(res)
        println("${sol.alpha} ${sol.beta} ${sol.gamma}")
    }
}

data class Solution(val alpha: Int, val beta: Int, val gamma: Int)