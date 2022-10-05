import kotlin.math.min
import kotlin.math.roundToInt

fun main() {
    val (n, k, l) = readLine()!!.split(" ").map { it.toInt() }
    if (k.toLong() * l.toLong() > n.toLong()) {
        println(0)
        return
    }
    val s = readLine()!!
    val answer = min(
            solve(n, k, l, s.map { it in 'a'..'z' }),
            solve(n, k, l, s.map { it in 'A'..'Z' })
    )
    println(answer)
}

fun solve(n: Int, k: Int, l: Int, present: List<Boolean>): Int {
    val sums = DoubleArray(n + 1)
    for (j in 1..n) {
        sums[j] = sums[j - 1] + (if (present[j - 1]) 1 else 0)
    }
    val dp = DoubleArray(n + 1)
    val amtUsed = IntArray(n + 1)
    fun solveWithPenalty(penalty: Double): Pair<Double, Int> {
        dp.fill(.0)
        amtUsed.fill(0)
        for (j in l..n) {
            val pos = dp[j - l] + (sums[j] - sums[j - l]) - penalty
            if (dp[j - 1] > pos) {
                dp[j] = dp[j - 1]
                amtUsed[j] = amtUsed[j - 1]
            } else {
                dp[j] = pos
                amtUsed[j] = amtUsed[j - l] + 1
            }
        }
        //println("penalty = $penalty, res = ${dp[n]}, amt = ${amtUsed[n]}")
        return Pair(dp[n], amtUsed[n])
    }
    var upper = l.toDouble()
    var lower = .0
    while (upper - lower > .00000001) {
        val mid = (upper + lower) / 2.0
        val amtUsed = solveWithPenalty(mid).second
        if (amtUsed < k) {
            upper = mid
        } else {
            lower = mid
        }
    }
    val (res, _) = solveWithPenalty(upper)
    return (sums[n] - (res + (upper * k.toDouble()))).roundToInt()
}