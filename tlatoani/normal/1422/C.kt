const val MOD = 1000000007L
const val NINTH = 111111112L

fun main() {
    val n = readLine()!!.reversed()
    val pow10 = LongArray(n.length + 1)
    pow10[0] = 1L
    for (j in 1..n.length) {
        pow10[j] = (10L * pow10[j - 1]) % MOD
    }
    var answer = 0L
    for ((j, chara) in n.withIndex()) {
        val d = (chara - '0').toLong()
        val rem = (n.length - 1 - j).toLong()
        val factor = (((((rem * (rem + 1L)) / 2L) % MOD) * pow10[j]) + (NINTH * (((j.toLong() * pow10[j]) - ((pow10[j] - 1L) * NINTH)) % MOD))) % MOD
        //println("j = $j, factor = ${(factor + MOD) % MOD}, d = $d")
        answer += d * factor
        answer %= MOD
    }
    answer += MOD
    answer %= MOD
    println(answer)
}