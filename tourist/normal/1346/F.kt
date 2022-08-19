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
    var (n, m, q) = readInts()
    var a = Array(n, {IntArray(m)})
    var row = LongArray(n)
    var col = LongArray(m)
    var total = 0L
    for (i in 0 until n) {
        var foo = readInts()
        for (j in 0 until m) {
            a[i][j] = foo[j]
            total += a[i][j]
            row[i] = row[i] + a[i][j]
            col[j] = col[j] + a[i][j]
        }
    }
    var res = LongArray(q + 1)
    for (qq in 0 until q + 1) {
        var bi = -1
        var sum = 0L
        while (2 * sum < total) {
            bi += 1
            sum += row[bi]
        }
        var bj = -1
        sum = 0L
        while (2 * sum < total) {
            bj += 1
            sum += col[bj]
        }
        var ans = 0L
        for (i in 0 until n) {
            ans += row[i].toLong() * kotlin.math.abs(i - bi)
        }
        for (j in 0 until m) {
            ans += col[j].toLong() * kotlin.math.abs(j - bj)
        }
        res[qq] = ans
        if (qq < q) {
            var (i, j, x) = readInts()
            i -= 1
            j -= 1
            total += x - a[i][j]
            row[i] = row[i] + x - a[i][j]
            col[j] = col[j] + x - a[i][j]
            a[i][j] = x
        }
    }
    println(res.joinToString(" "))
}