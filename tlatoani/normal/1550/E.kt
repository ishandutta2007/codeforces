import kotlin.math.min

fun main() {
    val (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val s = readLine()!!.map { if (it == '?') k else it - 'a' }
    var upper = n
    var lower = 0
    val dp1 = Array(n + 1) { IntArray(k) { n + 1 } }
    val dp2 = Array(n + 1) { IntArray(k) }
    val bits = Array(1 shl k) { mask -> (0 until k).filter { (mask shr it) and 1 == 1 }.toIntArray() }
    while (upper > lower) {
        val mid = (upper + lower + 1) / 2
        dp1[n].fill(n + 1)
        dp2[n].fill(0)
        for (j in n - 1 downTo 0) {
            for (letter in 0 until k) {
                dp1[j][letter] = dp1[j + 1][letter]
                dp2[j][letter] = if (s[j] == letter || s[j] == k) dp2[j + 1][letter] + 1 else 0
                if (dp2[j][letter] >= mid) {
                    dp1[j][letter] = j + mid
                }
            }
        }
        val dp3 = IntArray(1 shl k) { n + 1 }
        dp3[0] = 0
        for (mask in 1 until (1 shl k)) {
            for (letter in bits[mask]) {
                val s = dp3[mask - (1 shl letter)]
                if (s <= n) {
                    dp3[mask] = min(dp3[mask], dp1[s][letter])
                }
            }
        }
        if (dp3.last() <= n) {
            lower = mid
        } else {
            upper = mid - 1
        }
    }
    println(upper)
}