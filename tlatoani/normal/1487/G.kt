const val MOD = 998244353L

fun main() {
    val n = readLine()!!.toInt()
    val caps = readLine()!!.split(" ").map { it.toInt() }
    var answer = 676L
    for (j in 3..n) {
        answer *= 25L
        answer %= MOD
    }
    val dp = Array(3) { Array(((n + 1) / 2) + 1) { LongArray(((n + 1) / 2) + 1) } }
    dp[0][0][0] = 1L
    for (a in 1..(n + 1) / 2) {
        for (b in 0..(n + 1) / 2) {
            dp[1][a][b] = ((25L * (dp[0][a - 1][b] + dp[2][a - 1][b])) + (24L * (dp[1][a - 1][b]))) % MOD
            if (b > 0) {
                dp[2][a][b] = (dp[0][a - 1][b - 1] + dp[1][a - 1][b - 1]) % MOD
            }
        }
    }
    for (a in n / 2..(n + 1) / 2) {
        for (b in 0..(n + 1) / 2) {
            dp[0][a][b] = (dp[1][a][b] + dp[2][a][b]) % MOD
        }
    }
    val mixed = LongArray(n + 1)
    for (a in 0..n / 2) {
        for (b in 0..(n + 1) / 2) {
            mixed[a + b] = (mixed[a + b] + (dp[0][n / 2][a] * dp[0][(n + 1) / 2][b])) % MOD
        }
    }
    for (a in n - 1 downTo 0) {
        mixed[a] = (mixed[a] + mixed[a + 1]) % MOD
    }
    val dp2 = Array(4) { Array(((n + 1) / 2) + 1) { Array(((n + 1) / 2) + 1) { LongArray(((n + 1) / 2) + 1) } } }
    dp2[0][0][0][0] = 1L
    for (a in 1..(n + 1) / 2) {
        for (b in 0..(n + 1) / 2) {
            for (c in 0..(n + 1) / 2) {
                dp2[1][a][b][c] = ((24L * (dp2[0][a - 1][b][c] + dp2[2][a - 1][b][c] + dp2[3][a - 1][b][c])) + (23L * (dp2[1][a - 1][b][c]))) % MOD
                if (b > 0) {
                    dp2[2][a][b][c] = (dp2[0][a - 1][b - 1][c] + dp2[1][a - 1][b - 1][c] + dp2[3][a - 1][b - 1][c]) % MOD
                }
                if (c > 0) {
                    dp2[3][a][b][c] = (dp2[0][a - 1][b][c - 1] + dp2[1][a - 1][b][c - 1] + dp2[2][a - 1][b][c - 1]) % MOD
                }
            }
        }
    }
    for (a in n / 2..(n + 1) / 2) {
        for (b in 0..(n + 1) / 2) {
            for (c in 0..(n + 1) / 2) {
                dp2[0][a][b][c] = (dp2[1][a][b][c] + dp2[2][a][b][c] + dp2[3][a][b][c]) % MOD
            }
        }
    }
    val mixed2 = Array(n + 1) { LongArray(n + 1) }
    for (a in 0..n / 2) {
        for (b in 0..(n + 1) / 2) {
            for (c in 0..(n / 2) - a) {
                for (d in 0..((n + 1) / 2) - b) {
                    mixed2[a + b][c + d] = (mixed2[a + b][c + d] + (dp2[0][n / 2][a][c] * dp2[0][(n + 1) / 2][b][d])) % MOD
                }
            }
        }
    }
    for (a in n downTo 0) {
        for (b in n downTo 0) {
            if (a < n) {
                mixed2[a][b] += mixed2[a + 1][b]
            }
            if (b < n) {
                mixed2[a][b] += mixed2[a][b + 1]
            }
            if (a < n && b < n) {
                mixed2[a][b] -= mixed2[a + 1][b + 1]
            }
            mixed2[a][b] %= MOD
        }
    }
    for (chara in 0..25) {
        if (caps[chara] < n) {
            answer -= mixed[caps[chara] + 1]
            answer %= MOD
            for (frisk in chara + 1..25) {
                if (caps[frisk] < n) {
                    answer += mixed2[caps[chara] + 1][caps[frisk] + 1]
                    answer %= MOD
                }
            }
        }
    }
    answer += MOD
    answer %= MOD
    println(answer)
}