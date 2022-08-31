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
    var tt = readInt()
    for (qq in 0 until tt) {
        var (n, k) = readInts()
        var s = readLn()
        var ans = k
        var balance = 0
        for (c in s) {
            if (c == '(') {
                balance += 1
            } else {
                balance -= 1
            }
            if (balance == 0) {
                ans += 1
            }
        }
        ans = minOf(ans, n / 2)
        println(ans)
    }
}