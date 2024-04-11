import java.lang.Double.max
import java.lang.Math.abs
import java.lang.Math.sqrt

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, l) = readInts()
    var x = IntArray(n + 1)
    var b = IntArray(n + 1)
    for (i in 1..n) {
        var (foo, bar) = readInts()
        x[i] = foo
        b[i] = bar
    }
    n++
    var low = 0.0
    var high = 1e10
    var res = ArrayList<Int>()
    for (it in 0..200) {
        var mid = (low + high) * 0.5
        var dp = DoubleArray(n, { 1e30 })
        var pr = IntArray(n)
        dp[0] = 0.0
        for (i in 0..n - 1) {
            for (j in i + 1..n - 1) {
                var ft = dp[i] + sqrt(abs(l - (x[j] - x[i])).toDouble()) - mid * b[j]
                if (ft < dp[j]) {
                    dp[j] = ft
                    pr[j] = i
                }
            }
        }
        if (dp[n - 1] <= 0) {
            high = mid
            res.clear()
            var i = n - 1
            while (i > 0) {
                res.add(i)
                i = pr[i]
            }
            res.reverse()
        } else {
            low = mid
        }
    }
    println(res.joinToString(" "))
}