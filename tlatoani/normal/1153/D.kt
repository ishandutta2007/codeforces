import java.util.*
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    var k = 0
    val isParent = BooleanArray(n + 1)
    val bits = IntArray(n + 1) { j -> if (j == 0) 0 else jin.nextInt() }
    val parent = IntArray(n + 1) { j -> if (j <= 1) 0 else {
        val p = jin.nextInt()
        isParent[p] = true
        p
    } }
    val dp = IntArray(n + 1) { j -> when (isParent[j]) {
        true -> when (bits[j]) {
            0 -> 0
            else -> Int.MAX_VALUE
        }
        false -> 1
    } }
    for (j in n downTo 2) {
        if (!isParent[j]) {
            k++
        }
        when (bits[parent[j]]) {
            0 -> dp[parent[j]] += dp[j]
            1 -> dp[parent[j]] = min(dp[parent[j]], dp[j])
        }
    }
    //println(dp.contentToString())
    println(k - dp[1] + 1)
}