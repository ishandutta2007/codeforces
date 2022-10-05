import java.util.*

fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toInt()
    val m = line.substring(six + 1).toInt()
    val prohibido = mutableSetOf<Int>()
    if (n > 0) {
        val tokenizer = StringTokenizer(readLine()!!)
        for (j in 1..n) {
            prohibido.add(tokenizer.nextToken().toInt())
        }
    }
    val factors = mutableListOf<Int>()
    for (f in 1..m) {
        if (m % f == 0) {
            factors.add(f)
        }
    }
    val elems = Array(m + 1) { mutableListOf<Long>() }
    for (k in 0 until m) {
        if (!prohibido.contains(k)) {
            val g = gcd(k, m)
            elems[g].add(k.toLong())
        }
    }
    val dp = IntArray(m + 1)
    val dpPrev = IntArray(m + 1)
    var totient = 1
    for (f in factors) {
        var isPrime = f != 1
        for (g in factors) {
            if (f % g == 0 && f != g) {
                if (g != 1) {
                    isPrime = false
                }
                if (dp[g] > dp[f]) {
                    dp[f] = dp[g]
                    dpPrev[f] = g
                }
            }
        }
        if (isPrime) {
            var mt = m
            while (mt % f == 0) {
                totient *= f
                mt /= f
            }
            totient /= f
            totient *= f - 1
        }
        dp[f] += elems[f].size
    }
    val ml = m.toLong()
    val answer = mutableListOf<Long>()
    var f = m
    while (elems[f].size == 0) {
        f = dpPrev[f]
    }
    while (f != 0) {
        val fl = f.toLong()
        for (j in elems[f].size - 1 downTo 1) {
            answer.add(((elems[f][j] / fl) * pow(elems[f][j - 1] / fl, totient - 1, ml)) % ml)
        }
        if (dpPrev[f] == 0) {
            answer.add(elems[f][0] % ml)
            break
        } else {
            val fn = dpPrev[f]
            val fnl = fn.toLong()
            answer.add(((elems[f][0] / fnl) * pow(elems[fn].last() / fnl, totient - 1, ml)) % ml)
            f = fn
        }
    }
    println(answer.size)
    println(answer.reversed().joinToString(" "))
}

fun pow(k: Long, e: Int, m: Long): Long {
    var s = k
    var ev = e
    var res = 1L
    while (ev > 0) {
        if (ev % 2 == 1) {
            res *= s
            res %= m
        }
        ev /= 2
        s *= s
        s %= m
    }
    return res
}

fun gcd(a: Int, b: Int): Int {
    var alpha = a
    var beta = b
    while (beta != 0) {
        alpha %= beta
        val gamma = alpha
        alpha = beta
        beta = gamma
    }
    return alpha
}