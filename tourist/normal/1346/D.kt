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
        var (n, m) = readInts()
        var v = IntArray(m)
        var u = IntArray(m)
        var w = IntArray(m)
        for (i in 0 until m) {
            var (x, y, z) = readInts()
            v[i] = x - 1
            u[i] = y - 1
            w[i] = z
        }
        var a = IntArray(n)
        for (i in 0 until m) {
            a[v[i]] = maxOf(a[v[i]], w[i])
            a[u[i]] = maxOf(a[u[i]], w[i])
        }
        var ok = true
        for (i in 0 until m) {
            if (minOf(a[v[i]], a[u[i]]) != w[i]) {
                ok = false
                break
            }
        }
        if (ok) {
            println("YES")
            println(a.joinToString(" "))
        } else {
            println("NO")
        }
    }
}