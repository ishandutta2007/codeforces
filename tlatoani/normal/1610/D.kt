const val MOD = 1000000007L

fun main() {
    val n = readLine()!!.toInt()
    val pow2 = LongArray(n + 1)
    pow2[0] = 1L
    for (j in 1..n) {
        pow2[j] = (2L * pow2[j - 1]) % MOD
    }
    val freq = IntArray(30)
    for (x in readLine()!!.split(" ").map { it.toInt() }) {
        var x = x
        var d = 0
        while (x % 2 == 0) {
            x /= 2
            d++
        }
        freq[d]++
    }
    var rem = n
    var answer = 0L
    rem -= freq[0]
    answer += (pow2[freq[0]] - 1L) * pow2[rem]
    answer %= MOD
    for (d in 1..29) {
        if (freq[d] > 0) {
            rem -= freq[d]
            answer += (pow2[freq[d] - 1] - 1L) * pow2[rem]
            answer %= MOD
        }
    }
    answer += MOD
    answer %= MOD
    println(answer)
}