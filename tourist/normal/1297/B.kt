private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var n = 0
var a = IntArray(0)
var b = IntArray(0)
var ans = 0

fun test(x: Int) {
    var cnt = 0
    for (i in 0 until n) {
        if (a[i] <= x && x <= b[i]) {
            cnt += 1
        }
    }
    if (cnt == 1) {
        ans = x
    }
}

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        n = readInt()
        a = IntArray(n)
        b = IntArray(n)
        for (i in 0 until n) {
            var (x, y) = readInts()
            a[i] = x
            b[i] = y
        }
        ans = -1
        for (i in 0 until n) {
            test(a[i])
            test(b[i])
            test(a[i] - 1)
            test(b[i] + 1)
        }
        println(ans)
    }
}