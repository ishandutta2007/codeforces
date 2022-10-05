fun main() {
    val weights = listOf(false) + readLine()!!.map { it == '1' }
    val m = readLine()!!.toInt()
    val dp = Array(m + 1) { Array(11) { IntArray(11) { -1 } } }
    dp[0][0][0] = 0
    for (j in 0 until m) {
        for (d in 0..10) {
            for (last in 0..10) {
                if (dp[j][d][last] != -1) {
                    for (next in d + 1..10) {
                        if (weights[next] && next != last) {
                            dp[j + 1][next - d][next] = last
                        }
                    }
                }
            }
        }
    }
    for (d in 1..10) {
        for (last in 1..10) {
            if (dp[m][d][last] != -1) {
                println("YES")
                val answer = mutableListOf<Int>()
                var dc = d
                var w = last
                for (j in m downTo 1) {
                    answer.add(w)
                    dc = w - dc
                    w = dp[j][w - dc][w]
                }
                println(answer.reversed().joinToString(" "))
                return
            }
        }
    }
    println("NO")
}