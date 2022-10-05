fun main() {
    val line = readLine()!!
    val six = line.indexOf(' ')
    val n = line.substring(0, six).toLong()
    val k = line.substring(six + 1).toLong()
    var len = 0
    while (1L shl len <= n) {
        len++
    }
    fun amt(d: Long): Long {
        var res = 0L
        if (d % 2L == 0L) {
            res += amt(d + 1L)
        }
        var l = 0
        while (1L shl l <= d) {
            l++
        }
        var l2 = l
        while (l2 < len) {
            res += 1L shl (l2 - l)
            l2++
        }
        val q = n / (1L shl (len - l))
        if (q > d) {
            res += 1L shl (len - l)
        } else if (q == d) {
            res += (n % (1L shl (len - l))) + 1L
        }
        //println("amt($d) = $res")
        return res
    }
    var lower = 0L
    var upper = n / 2L
    while (upper > lower) {
        val mid = (lower + upper + 1L) / 2L
        if (amt(2L * mid) >= k) {
            lower = mid
        } else {
            upper = mid - 1L
        }
    }
    var answer = upper * 2L
    if (amt(answer + 1L) >= k) {
        answer++
    }
    println(answer)
}