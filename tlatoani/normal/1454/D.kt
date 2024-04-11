fun main() {
    val isPrime = BooleanArray(100000) { true }
    val primes = mutableListOf<Long>()
    for (p in 2 until 100000) {
        if (isPrime[p]) {
            primes.add(p.toLong())
            for (k in 2 * p until 100000 step p) {
                isPrime[k] = false
            }
        }
    }
    val out = StringBuilder()
    for (c in 1..readLine()!!.toInt()) {
        var n = readLine()!!.toLong()
        val primeFactorization = mutableListOf<Pair<Long, Int>>()
        for (p in primes) {
            var e = 0
            while (n % p == 0L) {
                n /= p
                e++
            }
            if (e != 0) {
                primeFactorization.add(Pair(p, e))
            }
        }
        if (n != 1L) {
            primeFactorization.add(Pair(n, 1))
        }
        val answer = LongArray(primeFactorization.map { it.second }.max()!!) { 1L }
        for ((p, e) in primeFactorization) {
            for (j in 0 until e) {
                answer[j] *= p
            }
        }
        out.appendln(answer.size).appendln(answer.reversed().joinToString(" "))
    }
    print(out)
}