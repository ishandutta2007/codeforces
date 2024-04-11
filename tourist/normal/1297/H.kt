private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        var s = readLn()
        var n = s.length
        var dp = Array(n + 1, { Array(n + 1, { "}" }) })
        dp[0][0] = ""
        var pr = Array(n + 1, { IntArray(n + 1, { -1 }) })
        var ans = "}"
        var color = CharArray(n)
        for (i in 0..n-1) {
            for (j in (i+1)/2..i) {
                if (dp[i][j] == "}") {
                    continue
                }
                var ft = dp[i][j] + s[i]
                if (ft < dp[i + 1][j + 1]) {
                    dp[i + 1][j + 1] = ft
                    pr[i + 1][j + 1] = 1
                }
                var k = i - j
                if (k < j && s[i] == dp[i][j][k]) {
                    if (dp[i][j] < dp[i + 1][j]) {
                        dp[i + 1][j] = dp[i][j]
                        pr[i + 1][j] = 0
                    }
                }
                if (k < j && s[i] > dp[i][j][k]) {
                    var cand = dp[i][j].substring(0, k) + s[i]
                    if (cand < ans) {
                        ans = cand
                        for (t in i + 1..n - 1) {
                            color[t] = 'R'
                        }
                        color[i] = 'B'
                        var cj = j
                        for (ci in i downTo 1) {
                            if (pr[ci][cj] == 1) {
                                color[ci - 1] = 'R'
                                cj -= 1
                            } else {
                                color[ci - 1] = 'B'
                            }
                        }
                    }
                }
                if (k < j && s[i] < dp[i][j][k]) {
                    var cand = dp[i][j]
                    if (cand < ans) {
                        ans = cand
                        for (t in i..n - 1) {
                            color[t] = 'B'
                        }
                        var cj = j
                        for (ci in i downTo 1) {
                            if (pr[ci][cj] == 1) {
                                color[ci - 1] = 'R'
                                cj -= 1
                            } else {
                                color[ci - 1] = 'B'
                            }
                        }
                    }
                }
            }
        }
        for (j in (n+1)/2..n) {
            if (dp[n][j] < ans) {
                ans = dp[n][j]
                var cj = j
                for (ci in n downTo 1) {
                    if (pr[ci][cj] == 1) {
                        color[ci - 1] = 'R'
                        cj -= 1
                    } else {
                        color[ci - 1] = 'B'
                    }
                }
            }
        }
        println(color.joinToString(""))
    }
}