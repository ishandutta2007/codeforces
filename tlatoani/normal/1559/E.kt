const val MOD = 998244353L

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val lastPrime = IntArray(m + 1)
    val sign = LongArray(m + 1)
    sign[1] = 1L
    for (p in 2..m) {
        if (lastPrime[p] == 0) {
            for (k in p..m step p) {
                lastPrime[k] = p
                if (lastPrime[k / p] == p) {
                    sign[k] = 0L
                } else {
                    sign[k] = -sign[k / p]
                }
            }
        }
    }
    val stars = Array(n) {
        val (l, r) = readLine()!!.split(" ").map { it.toInt() }
        Pair(l, r)
    }
    var answer = 0L
    factorLoop@for (k in 1..m) {
        if (sign[k] != 0L) {
            var baseSum = 0
            for ((l) in stars) {
                baseSum += (l + k - 1) / k
                if (baseSum > m / k) {
                    continue@factorLoop
                }
            }
            var dpPrev = LongArray((m / k) - baseSum + 1)
            dpPrev[0] = 1L
            var dpNext = LongArray((m / k) - baseSum + 1)
            for ((l, r) in stars) {
                val range = (r / k) - ((l + k - 1) / k)
                if (range < 0) {
                    continue@factorLoop
                }
                dpNext[0] = dpPrev[0]
                for (j in 1 until dpNext.size) {
                    dpNext[j] = dpPrev[j] + dpNext[j - 1]
                    if (j > range) {
                        dpNext[j] -= dpPrev[j - range - 1]
                    }
                    if (dpNext[j] >= MOD) {
                        dpNext[j] -= MOD
                    } else if (dpNext[j] < 0L) {
                        dpNext[j] += MOD
                    }
                }
                val temp = dpPrev
                dpPrev = dpNext
                dpNext = temp
            }
            answer += sign[k] * dpPrev.sum()
            answer %= MOD
        }
    }
    answer += MOD
    answer %= MOD
    println(answer)
}