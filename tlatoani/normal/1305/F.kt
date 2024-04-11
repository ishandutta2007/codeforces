import java.util.*
import kotlin.math.min

fun main() {
    val startTime = System.currentTimeMillis()
    val isPrime = BooleanArray(500001) { true }
    val primes = mutableListOf<Long>()
    for (j in 1..500000) {
        if (isPrime[j]) {
            val p = ((2 * j) + 1).toLong()
            primes.add(p)
            var k = p * p
            while (k <= 1000000L) {
                isPrime[k.toInt() / 2] = false
                k += 2L * p
            }
        }
    }
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    val array = LongArray(n) { tokenizer.nextToken().toLong() }
    val different = mutableSetOf<Long>()
    for (a in array) {
        different.add(a)
        different.add(a + 1L)
        different.add(a - 1L)
    }
    different.remove(0L)
    val dlist = different.toList()
    val random = Random(System.currentTimeMillis() + 2349876283734L)
    var answer = n
    val tried = mutableSetOf<Long>()
    fun attempt(p: Long) {
        if (tried.contains(p)) {
            return
        }
        tried.add(p)
        var pos = 0L
        for (a in array) {
            if (a < p) {
                pos += p - a
            } else {
                pos += min(a % p, p - (a % p))
            }
            if (pos > answer) {
                return
            }
        }
        if (pos < answer) {
            answer = pos.toInt()
        }
    }
    attempt(2L)
    while (System.currentTimeMillis() - startTime <= 2400L) {
        val r = random.nextInt(dlist.size)
        var k = dlist[r]
        while (k % 2L == 0L) {
            k /= 2L
        }
        val ps = mutableListOf<Long>()
        for (p in primes) {
            if (k % p == 0L) {
                ps.add(p)
                while (k % p == 0L) {
                    k /= p
                }
                if (k == 1L) {
                    break
                }
            }
        }
        if (k != 1L) {
            ps.add(k)
        }
        for (p in ps) {
            attempt(p)
        }
    }
    println(answer)
}

/*
4
63 29 133 707
 */