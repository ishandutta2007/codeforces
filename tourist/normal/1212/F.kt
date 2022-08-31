import java.lang.Math.abs

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var s = readLn().reversed() + "000"
    var len = s.length
    val MAX = 200
    var dp = Array(len + 1, { Array(2 * MAX, { IntArray(2 * MAX, { 12345 }) }) })
    dp[0][MAX][MAX] = 0
    for (i in 0..len - 1) {
        for (cur in -MAX..MAX-1) {
            for (carry in -MAX..MAX-1) {
                var ft = dp[i][cur + MAX][carry + MAX]
                if (ft == 12345) {
                    continue
                }
                for (delta in -100..100) {
                    var newCur = cur + delta
                    var here = newCur + carry
                    var value = (here % 10 + 10) % 10
                    if (value != s[i] - '0') {
                        continue
                    }
                    var newCarry = (here - value) / 10
                    var newFt = ft + abs(delta) * i
                    if (newCur >= -MAX && newCur < MAX && newCarry >= -MAX && newCarry < MAX && newFt < dp[i + 1][newCur + MAX][newCarry + MAX]) {
                        dp[i + 1][newCur + MAX][newCarry + MAX] = newFt
                    }
                }
            }
        }
    }
    println(dp[len][MAX][MAX])
}