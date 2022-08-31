private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, a, b, k) = readInts()
    val MAX = 1000010
    var cnt = IntArray(MAX)
    var r = readInts()
    for (x in r) cnt[x]++
    var ans = 0
    if (a > b) {
        for (i in 1..MAX - 1) {
            if (i * k >= MAX) {
                break
            }
            var x = cnt[i] / a
            var y = cnt[i * k] / b
            if (y < x) x = y
            ans += x
            cnt[i] -= a * x
            cnt[i * k] -= b * x
        }
    } else {
        for (i in (MAX - 1) downTo 1) {
            if (i * k >= MAX) {
                continue
            }
            var x = cnt[i] / a
            var y = cnt[i * k] / b
            if (y < x) x = y
            ans += x
            cnt[i] -= a * x
            cnt[i * k] -= b * x
        }
    }
    println(ans)
}