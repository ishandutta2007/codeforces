import kotlin.math.min

const val MOD = 998244353L

fun main() {
    val out = StringBuilder()
    val lastPrime = IntArray(200001)
    val divisibility = IntArray(200001)
    val rem = IntArray(200001)
    for (p in 2..200000) {
        if (lastPrime[p] == 0) {
            for (k in p..200000 step p) {
                lastPrime[k] = p
                divisibility[k] = 1 + (if ((k / p) % p == 0) divisibility[k / p] else 0)
                rem[k] = if ((k / p) % p == 0) rem[k / p] else (k / p)
            }
        }
    }
    val inverses = LongArray(200001) { it.toLong() pow -1 }
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val adj = Array(n + 1) { mutableListOf<Edge>() }
        repeat(n - 1) {
            val (a, b, x, y) = readLine()!!.split(" ").map { it.toInt() }
            adj[a].add(Edge(b, y, x))
            adj[b].add(Edge(a, x, y))
        }
        val currDivisibility = IntArray(n + 1)
        val minDivisibility = IntArray(n + 1)
        var total = 0L
        fun dfs(a: Int, num: Int, denom: Int, from: Int, value: Long) {
            total += value
            total %= MOD
            var x = num
            while (x != 1) {
                currDivisibility[lastPrime[x]] += divisibility[x]
                x = rem[x]
            }
            x = denom
            while (x != 1) {
                currDivisibility[lastPrime[x]] -= divisibility[x]
                minDivisibility[lastPrime[x]] = min(minDivisibility[lastPrime[x]], currDivisibility[lastPrime[x]])
                x = rem[x]
            }
            for ((b, nextNum, nextDenom) in adj[a]) {
                if (b != from) {
                    dfs(b, nextNum, nextDenom, a, (((value * nextNum.toLong()) % MOD) * inverses[nextDenom]) % MOD)
                }
            }
            x = num
            while (x != 1) {
                currDivisibility[lastPrime[x]] -= divisibility[x]
                x = rem[x]
            }
            x = denom
            while (x != 1) {
                currDivisibility[lastPrime[x]] += divisibility[x]
                x = rem[x]
            }
        }
        dfs(1, 1, 1, 0, 1L)
        for (p in 1..n) {
            total *= p.toLong() pow -minDivisibility[p]
            total %= MOD
        }
        out.appendln(total)
    }
    print(out)
}

data class Edge(val to: Int, val num: Int, val denom: Int)

const val MOD_TOTIENT = MOD.toInt() - 1

infix fun Long.pow(power: Int): Long {
    var e = power
    e %= MOD_TOTIENT
    if (e < 0) {
        e += MOD_TOTIENT
    }
    if (e == 0 && this == 0L) {
        return this
    }
    var b = this % MOD
    var res = 1L
    while (e > 0) {
        if (e and 1 != 0) {
            res *= b
            res %= MOD
        }
        b *= b
        b %= MOD
        e = e shr 1
    }
    return res
}