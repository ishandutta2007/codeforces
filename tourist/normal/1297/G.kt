private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (m, k) = readInts()
    var cnt = IntArray(10)
    for (i in 2..7) {
        while (m % i == 0) {
            m /= i
            cnt[i] += 1
        }
    }
    if (m > 1) {
        println("-1")
        return
    }
    var allow = minOf(50000,2000000 / (cnt[2] + 1) / (cnt[3] + 1) / (cnt[5] + 1) / (cnt[7] + 1))
    var dp = Array(allow) { Array(cnt[2] + 1) { Array(cnt[3] + 1) { Array(cnt[5] + 1) {IntArray(cnt[7] + 1) {0} } } } }
    dp[0][0][0][0][0] = 1
    for (i in 0 until dp.size - 1) {
        for (k2 in 0..cnt[2]) {
            for (k3 in 0..cnt[3]) {
                for (k5 in 0..cnt[5]) {
                    for (k7 in 0..cnt[7]) {
                        var ft = dp[i][k2][k3][k5][k7]
                        if (ft == 0) {
                            continue
                        }
                        for (d in 1..9) {
                            var n2 = k2
                            var n3 = k3
                            var n5 = k5
                            var n7 = k7
                            var x = d
                            while (x % 2 == 0) {
                                x /= 2
                                n2++
                            }
                            while (x % 3 == 0) {
                                x /= 3
                                n3++
                            }
                            while (x % 5 == 0) {
                                x /= 5
                                n5++
                            }
                            while (x % 7 == 0) {
                                x /= 7
                                n7++
                            }
                            if (n2 <= cnt[2] && n3 <= cnt[3] && n5 <= cnt[5] && n7 <= cnt[7]) {
                                dp[i + 1][n2][n3][n5][n7] = minOf(k, dp[i + 1][n2][n3][n5][n7] + ft)
                            }
                        }
                    }
                }
            }
        }
    }
    for (len in 1 until dp.size) {
        var k2 = cnt[2]
        var k3 = cnt[3]
        var k5 = cnt[5]
        var k7 = cnt[7]
        var cur = dp[len][k2][k3][k5][k7]
        if (k > cur) {
            k -= cur
            continue
        }
        for (i in 0 until len) {
            for (d in 1..9) {
                var n2 = k2
                var n3 = k3
                var n5 = k5
                var n7 = k7
                var x = d
                while (x % 2 == 0) {
                    x /= 2
                    n2--
                }
                while (x % 3 == 0) {
                    x /= 3
                    n3--
                }
                while (x % 5 == 0) {
                    x /= 5
                    n5--
                }
                while (x % 7 == 0) {
                    x /= 7
                    n7--
                }
                if (n2 >= 0 && n3 >= 0 && n5 >= 0 && n7 >= 0) {
                    var cur = dp[len - i - 1][n2][n3][n5][n7]
                    if (cur < k) {
                        k -= cur
                    } else {
                        print(d)
                        k2 = n2
                        k3 = n3
                        k5 = n5
                        k7 = n7
                        break
                    }
                }
            }
        }
        println()
        break
    }
}