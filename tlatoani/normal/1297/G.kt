fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    var m = line.substring(0, six).toLong()
    var mt = m
    while (mt % 2L == 0L) {
        mt /= 2L
    }
    while (mt % 3L == 0L) {
        mt /= 3L
    }
    while (mt % 5L == 0L) {
        mt /= 5L
    }
    while (mt % 7L == 0L) {
        mt /= 7L
    }
    if (mt != 1L) {
        println(-1)
        return
    }
    var k = line.substring(six + 1).toLong()
    val dp = mutableListOf<MutableMap<Long, Long>>()
    fun getDP(l: Int, n: Long): Long {
        if (l == 0) {
            return if (n == 1L) 1L else 0L
        }
        while (dp.size <= l) {
            dp.add(mutableMapOf())
        }
        if (!dp[l].containsKey(n)) {
            var res = 0L
            for (d in 1L..9L) {
                if (n % d == 0L) {
                    res += getDP(l - 1, n / d)
                }
            }
            dp[l][n] = res
        }
        //println("getDP($l, $n) = ${dp[l][n]!!}")
        return dp[l][n]!!
    }
    var l = 1
    while (getDP(l, m) < k) {
        k -= getDP(l, m)
        l++
    }
    val answer = StringBuilder()
    while (l > 0) {
        for (d in 1L..9L) {
            if (m % d == 0L) {
                if (getDP(l - 1, m / d) < k) {
                    k -= getDP(l - 1, m / d)
                } else {
                    answer.append(d)
                    m /= d
                    break
                }
            }
        }
        l--
    }
    println(answer)
}