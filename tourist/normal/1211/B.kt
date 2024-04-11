import java.lang.Math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var n = readInt()
    var a = readInts()
    var ans = 0L
    for (i in 0..n-1) {
        if (a[i] > 0) {
            var u = (a[i] - 1).toLong() * n + i + 1
            if (u > ans) ans = u
        }
    }
    println(ans)
}