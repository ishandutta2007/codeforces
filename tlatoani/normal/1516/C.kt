fun main() {
    val n = readLine()!!.toInt()
    val xs = readLine()!!.split(" ").map { it.toInt() }
    val s = xs.sum()
    if (s % 2 == 1) {
        println(0)
        return
    }
    val dp = BooleanArray((s / 2) + 1)
    dp[0] = true
    for (x in xs) {
        for (k in s / 2 downTo x) {
            dp[k] = dp[k] || dp[k - x]
        }
    }
    if (dp[s / 2]) {
        println(1)
        println((1..n).minBy {
            var x = xs[it - 1]
            var res = 0
            while (x % 2 == 0) {
                res++
                x /= 2
            }
            res
        })
    } else {
        println(0)
    }
}