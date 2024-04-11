import kotlin.math.max
import kotlin.math.min

fun main() {
    val isPrime = BooleanArray(200001) { true }
    isPrime[1] = false
    val primes = mutableListOf<Int>()
    var maxGap = 0
    for (p in 2..200000) {
        if (isPrime[p]) {
            if (primes.isNotEmpty()) {
                maxGap = max(maxGap, p - primes.last())
            }
            primes.add(p)
            for (k in 2 * p..200000 step p) {
                isPrime[k] = false
            }
        }
    }
    val maxPrimeFactor = IntArray(1000001)
    for (p in primes) {
        for (k in p..1000000 step p) {
            maxPrimeFactor[k] = p
        }
    }
    //println("max gap = $maxGap")
    val out = StringBuilder()
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        fun query(j: Int, k: Int): Long {
            println("? $j $k")
            return readLine()!!.toLong()
        }
        val answer = LongArray(n + 1)
        if (n <= 100) {
            val queries = Array(n + 1) { mutableListOf<Long>() }
            for (j in 1..n) {
                for (k in j + 1..n) {
                    val x = query(j, k)
                    queries[j].add(x)
                    queries[k].add(x)
                }
            }
            var l = 200000L
            for (j in 1..n) {
                l = min(l, queries[j].reduce { x, y -> gcd(x, y) })
            }
            val r = l + n.toLong() - 1L
            val byQueries = mutableMapOf<List<Long>, Long>()
            for (x in l..r) {
                val here = mutableListOf<Long>()
                for (y in l..r) {
                    if (y != x) {
                        here.add((x * y) / gcd(x, y))
                    }
                }
                here.sort()
                byQueries[here] = x
            }
            queries.forEach { it.sort() }
            for (j in 1..n) {
                answer[j] = byQueries[queries[j]]!!
            }
        } else {
            val shuffled = (1..n).shuffled()
            var primeIndex = 0
            var prime = (n / 2).toLong()
            var trials = 0
            for (j in n - 1 downTo 0) {
                if (trials > 100) {
                    break
                }
                trials++
                var g = 0L
                var k = 0
                while (g == 0L || g > 1000000L || k < min(11, n)) {
                    if (j != k) {
                        g = gcd(g, query(shuffled[j], shuffled[k]))
                    }
                    k++
                }
                if (maxPrimeFactor[g.toInt()] > prime) {
                    primeIndex = shuffled[j]
                    prime = maxPrimeFactor[g.toInt()].toLong()
                }
            }
            answer[primeIndex] = prime
            for (j in 1..n) {
                if (j != primeIndex) {
                    answer[j] = query(primeIndex, j) / prime
                }
            }
        }
        println("! " + answer.toList().subList(1, n + 1).joinToString(" "))
    }
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)