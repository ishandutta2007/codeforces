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
    var (n, m, k) = readInts()
    val inf = 787788
    var a = IntArray(n)
    for (i in 0 until n) {
        a[i] = inf
    }
    a[k - 1] = 0
    for (i in 0 until m) {
        var (x, y) = readInts()
        x -= 1
        y -= 1
        var ax = minOf(a[x] + 1, a[y])
        var ay = minOf(a[y] + 1, a[x])
        a[x] = ax
        a[y] = ay
    }
    for (i in 0 until n) {
        if (a[i] == inf) {
            a[i] = -1
        }
    }
    println(a.joinToString(" "))
}