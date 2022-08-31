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
    var n = readInt()
    var a = IntArray(n)
    for (i in 1 until n+1) {
        for (j in 2 until n/i+1) {
            a[i * j - 1] += 1
            a[i - 1] -= 1
        }
    }
    a.sortDescending()
    var ans = IntArray(n)
    for (i in 0 until n) {
        ans[i] = a[i]
        if (i > 0) {
            ans[i] += ans[i - 1]
        }
    }
    println(ans.joinToString( " "))
}