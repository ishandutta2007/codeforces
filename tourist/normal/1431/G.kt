import java.lang.AssertionError

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

fun main(args: Array<String>) {
    var (n, k) = readInts()
    var a = readInts().sorted()
    var dp = Array(n + 1) {IntArray(k + 1) {-1}}
    dp[0][0] = 0
    for (i in 0 until n) {
        for (j in 0..k) {
            if (dp[i][j] == -1) {
                continue
            }
            dp[i + 1][j] = maxOf(dp[i + 1][j], dp[i][j])
            var limit = minOf(k - j, (n - i) / 2)
            var add = 0
            for (x in 1..limit) {
                add += a[i + 2 * x - 2]
                add += a[i + 2 * x - 1]
                add -= 2 * a[i + x - 1]
                dp[i + 2 * x][j + x] = maxOf(dp[i + 2 * x][j + x], dp[i][j] + add)
            }
        }
    }
    println(dp[n][k])
}