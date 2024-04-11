fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val competitions = Array(n) {
        val (k, t) = readLine()!!.split(" ").map { it.toInt() }
        Competition(k, t == 2)
    }
    val totalAlternating = competitions.filter { it.alternating }.sumBy { it.stages }
    val totalOther = competitions.filter { !it.alternating }.sumBy { it.stages }
    if (totalAlternating > m) {
        println(-1)
        return
    }
    val dp = Array(n + 1) { IntArray((totalAlternating / 2) + 1) { -1 } }
    dp[0][0] = 0
    for (j in 0 until n) {
        for (x in 0..totalAlternating / 2) {
            if (dp[j][x] >= 0) {
                dp[j + 1][x] = 0
            }
        }
        if (competitions[j].alternating) {
            for (x in totalAlternating / 2 downTo competitions[j].stages) {
                if (dp[j][x - competitions[j].stages] >= 0) {
                    dp[j + 1][x] = 1
                }
            }
        }
    }
    var x = (0..totalAlternating / 2).last { dp[n][it] >= 0 }
    if ((2 * (totalAlternating - x)) + (if (2 * x == totalAlternating) 0 else -1) + totalOther > m) {
        println(-1)
        return
    }
    val answer = IntArray(n)
    var day = 1
    for (j in 0 until n) {
        if (!competitions[j].alternating) {
            answer[j] = day
            day += competitions[j].stages
        }
    }
    val smallerHalf = mutableSetOf<Int>()
    for (j in n - 1 downTo 0) {
        if (dp[j + 1][x] == 1) {
            smallerHalf.add(j)
            x -= competitions[j].stages
        }
    }
    var day1 = day
    for (j in 0 until n) {
        if (competitions[j].alternating && j !in smallerHalf) {
            answer[j] = day1
            day1 += 2 * competitions[j].stages
        }
    }
    var day2 = day + 1
    for (j in 0 until n) {
        if (j in smallerHalf) {
            answer[j] = day2
            day2 += 2 * competitions[j].stages
        }
    }
    println(answer.joinToString(" "))
}

data class Competition(val stages: Int, val alternating: Boolean)