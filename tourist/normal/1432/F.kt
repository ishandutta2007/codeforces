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
    var (n, m, d) = readInts()
    var c = readInts()
    var s = 0
    for (i in 0 until m) {
        s += c[i]
    }
    if (s > n || s + (d - 1) * (m + 1) < n) {
        println("NO")
        return
    }
    println("YES")
    var x = n - s
    var r = IntArray(n)
    var pos = 0
    for (i in 0 until m) {
        var z = minOf(d - 1, x)
        for (j in 0 until z) {
            r[pos] = 0
            pos += 1
        }
        for (j in 0 until c[i]) {
            r[pos] = i + 1
            pos += 1
        }
        x -= z
    }
//    myAssert(x == 0)
    println(r.joinToString(" "))
}