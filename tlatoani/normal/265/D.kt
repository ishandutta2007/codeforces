import java.util.*

fun main() {
    val rem = TreeSet<Int>()
    val prime = mutableMapOf<Int, Int>()
    var i = 3
    while (i <= 100000) {
        rem.add(i)
        i += 2
    }
    while (rem.first() < 330) {
        val p = rem.first()
        prime[p] = p
        val toRemove = ArrayList<Int>()
        for (k in rem) {
            if (p * k > 100000) {
                break
            }
            prime[p * k] = p
            toRemove.add(p * k)
        }
        rem.removeAll(toRemove)
        rem.remove(p)
    }
    for (p in rem) {
        prime[p] = p
    }
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val array = IntArray(n) { jin.nextInt() }
    if (array.last() == 1) {
        println(1)
        return
    }
    val dp = mutableMapOf<Int, Int>()
    for (a in array) {
        var at = a
        val primeFactors = mutableSetOf<Int>()
        while (at % 2 == 0) {
            primeFactors.add(2)
            at /= 2
        }
        while (at != 1) {
            val p = prime[at]!!
            primeFactors.add(p)
            at /= p
        }
        var best = 0
        for (p in primeFactors) {
            dp[p]?.let { d ->
                if (d > best) {
                    best = d
                }
            }
        }
        best++
        for (p in primeFactors) {
            if ((dp[p] ?: 0) < best) {
                dp[p] = best
            }
        }
        //println("i = $i, primes = $primeFactors, best = $best")
    }
    println(dp.maxBy { it.component2() }!!.component2())
}