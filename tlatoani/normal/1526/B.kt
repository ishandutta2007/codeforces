fun main() {
    val dp = BooleanArray(11 * 111)
    dp[0] = true
    for (x in 1 until 11 * 111) {
        dp[x] = (x >= 11 && dp[x - 11]) || (x >= 111 && dp[x - 111]) || (x >= 1111 && dp[x - 1111])
    }
    repeat(readLine()!!.toInt()) {
        val x = readLine()!!.toInt()
        println(if (x >= 11 * 111 || dp[x]) "yEs" else "nO")
    }
}