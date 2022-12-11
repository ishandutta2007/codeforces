import java.util.*

fun buildPrefixSum(seq: List<Long>, range: IntProgression, threshold: Long): List<Pair<Long, Pair<Int, Int>>> {
    val sums = mutableListOf<Pair<Long, Pair<Int, Int>>>()
    for (i in range) {
        val value = seq[i] + (sums.lastOrNull()?.first ?: 0)
        if (value > threshold) {
            break
        }
        if (sums.any() && sums.last().first == value) {
            sums[sums.size - 1] = (sums.last().first to (sums.last().second.first to i))
        } else {
            sums.add(value to (i to i))
        }
    }
    return sums;
}

const val mod = 998244353L
fun add(a: Long, b: Long): Long {
    return (a + b) % mod
}

fun mult(a: Long, b: Long): Long {
    return (a * b) % mod
}

fun pow(a: Long, k: Long): Long {
    if (k == 0L) {
        return 1
    }
    if (k % 2 == 0L) {
        val t = pow(a, k / 2)
        return mult(t, t)
    }
    return mult(pow(a, k - 1), a)
}

fun inv(a: Long): Long {
    return pow(a, mod - 2)
}

val fact = Array<Long>(100_000 + 10) { 0 }
val ifact = Array<Long>(100_000 + 10) { 0 }

fun C(n: Int, k: Int): Long {
    return mult(fact[n], mult(ifact[n - k], ifact[k]))
}

fun main() {
    fact[0] = 1
    ifact[0] = 1
    for (i in 1 until fact.size) {
        fact[i] = mult(fact[i - 1], i.toLong())
        ifact[i] = inv(fact[i])
    }

    val reader = Scanner(System.`in`)
    val tests = reader.nextInt()
    for (t in 0 until tests) {
        val n = reader.nextInt()
        val seq = mutableListOf<Long>()
        var sum = 0L
        for (i in 0 until n) {
            val value = reader.nextLong()
            sum += value
            seq.add(value)
        }
        val prefix = buildPrefixSum(seq, 0 until n, sum / 2)
        val suffix = buildPrefixSum(seq, n - 1 downTo 0, sum / 2)
        var (a, b) = (0 to 0)
        var result = 1L
        while (a < prefix.size && b < suffix.size) {
            if (prefix[a].first < suffix[b].first) {
                a++
            } else if (prefix[a].first > suffix[b].first) {
                b++
            } else {
                var options = 1L
                var r = suffix[b].second.second
                for (i in prefix[a].second.first..prefix[a].second.second) {
                    while (r <= i) r++
                    val cntL = i - prefix[a].second.first
                    val cntR = suffix[b].second.first - r + 1;
                    if (cntR > 0)
                        options = add(options, C(cntL + cntR, cntR - 1))
                }

                result = mult(result, options)
                a++
                b++
            }
        }
        println(result)
    }
}