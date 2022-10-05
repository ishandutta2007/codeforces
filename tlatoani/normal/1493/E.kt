import java.io.BufferedReader
import java.io.InputStreamReader

const val MOD = 998244853L

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val pow2 = LongArray(n + 1)
    pow2[0] = 1L
    for (j in 1..n) {
        pow2[j] = (2L * pow2[j - 1]) % MOD
    }
    val l = jin.readLine().reversed()
    var lHash = 0L
    for (j in 0 until n) {
        if (l[j] == '1') {
            lHash += pow2[j]
            lHash %= MOD
        }
    }
    val r = jin.readLine().reversed().toCharArray()
    if (r.last() == '0') {
        println(0)
        return
    }
    val all = pow2[n] - 1L
    var rHash = 0L
    for (j in 0 until n) {
        if (r[j] == '1') {
            rHash += pow2[j]
            rHash %= MOD
        }
    }
    var rOddHash = rHash
    if (r[0] == '0') {
        rOddHash++
        rOddHash %= MOD
    }
    var rDecHash = (rHash - 1L + MOD) % MOD
    var answer = 0L
    fun calcAnswer() {
        answer = when {
            l.last() == '0' -> all
            lHash != rHash && lHash != rDecHash -> rOddHash
            else -> rHash
        }
    }
    calcAnswer()
    if (answer == all) {
        println("1".repeat(n))
    } else {
        if (answer == rOddHash) {
            r[0] = '1'
        }
        println(String(r).reversed())
    }
}