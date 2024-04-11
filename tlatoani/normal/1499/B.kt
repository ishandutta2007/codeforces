fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val s = "00" + readLine()!!
        val dp = BooleanArray(s.length)
        dp[0] = true
        dp[1] = true
        for (j in 2 until s.length) {
            for (k in j - 2..j - 1) {
                dp[j] = dp[j] || (s[k] <= s[j] && dp[k])
            }
        }
        println(if (dp[s.length - 2] || dp[s.length - 1]) "yEs" else "nO")
    }
}