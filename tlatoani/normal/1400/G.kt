import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244353L

fun main() {
    val factorial = LongArray(300001)
    factorial[0] = 1L
    for (j in 1..300000) {
        factorial[j] = (j.toLong() * factorial[j - 1]) % MOD
    }
    val factInv = LongArray(300001)
    factInv[300000] = factorial[300000] pow -1
    for (j in 299999 downTo 0) {
        factInv[j] = ((j + 1).toLong() * factInv[j + 1]) % MOD
    }
    fun choose(a: Int, b: Int) = if (a < 0 || b < 0 || b > a) 0L else (factorial[a] * ((factInv[b] * factInv[a - b]) % MOD)) % MOD
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val mercsAdd = Array(n) {
        val (l, r) = jin.readLine().split(" ").map { it.toInt() }
        Mercenary(it + 1, l, r)
    }
    val important = mutableSetOf<Int>()
    val prohibido = Array(m) {
        val (a, b) = jin.readLine().split(" ").map { it.toInt() }
        important.add(a)
        important.add(b)
        Pair(a, b)
    }
    val importantPlace = mutableMapOf<Int, Int>()
    for ((ix, j) in important.toList().withIndex()) {
        importantPlace[j] = ix
    }
    val covered = LongArray(1 shl m)
    for (e in prohibido.indices) {
        val (a, b) = prohibido[e]
        covered[1 shl e] = (1L shl importantPlace[a]!!) + (1L shl importantPlace[b]!!)
    }
    for (mask in covered.indices) {
        for (e in 0 until m) {
            covered[mask or (1 shl e)] = covered[mask or (1 shl e)] or covered[mask]
        }
    }
    val corrections = Array(41) { IntArray(1 shl m) }
    for (mask in covered.indices) {
        var coveredAMT = 0
        for (e in 0..39) {
            if (covered[mask] and (1L shl e) != 0L) {
                coveredAMT++
            }
        }
        corrections[coveredAMT][mask] += 1 - (2 * (Integer.bitCount(mask) % 2))
    }
    for (e in 0 until m) {
        for (mask in covered.indices) {
            val next = mask or (1 shl e)
            if (next != mask) {
                for (j in corrections.indices) {
                    corrections[j][next] += corrections[j][mask]
                }
            }
        }
    }
    val inside = BooleanArray(n + 1)
    val mercsRemove = Array(n) { mercsAdd[it] }
    mercsAdd.sortBy { it.from }
    mercsRemove.sortBy { it.to }
    var currMask = 0
    var currAMT = 0
    var answer = 0L
    var j1 = 0
    var j2 = 0
    for (k in 1..n) {
        while (j1 < n && mercsAdd[j1].from == k) {
            currAMT++
            inside[mercsAdd[j1].ix] = true
            for (e in 0 until m) {
                if (mercsAdd[j1].ix in prohibido[e] && inside[prohibido[e].first] && inside[prohibido[e].second]) {
                    currMask += 1 shl e
                }
            }
            j1++
        }
        while (j2 < n && mercsRemove[j2].to == k - 1) {
            for (e in 0 until m) {
                if (mercsRemove[j2].ix in prohibido[e] && inside[prohibido[e].first] && inside[prohibido[e].second]) {
                    currMask -= 1 shl e
                }
            }
            inside[mercsRemove[j2].ix] = false
            currAMT--
            j2++
        }
        for (d in corrections.indices) {
            answer += corrections[d][currMask].toLong() * choose(currAMT - d, k - d)
            answer %= MOD
        }
    }
    answer += MOD
    answer %= MOD
    println(answer)
}

data class Mercenary(val ix: Int, val from: Int, val to: Int)

operator fun <A> Pair<A, A>.contains(elem: A) = elem == this.first || elem == this.second

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