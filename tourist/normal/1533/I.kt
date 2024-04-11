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
    var (n1, n2, m) = readInts()
    var k = readInts()
    var p = IntArray(n1 + n2) {it}
    var b = BooleanArray(n1 + n2) {true}
    val inf = 1e9.toInt()
    var v = IntArray(n1 + n2) {it -> if (it < n1) k[it] else inf}
    fun get(x: Int): Int {
        if (x != p[x]) {
            p[x] = get(p[x])
        }
        return p[x]
    }
    fun unite(x: Int, y: Int) {
        var px = get(x)
        var py = get(y)
        if (px == py) {
            b[px] = false
        } else {
            p[px] = py
            b[py] = (b[py] and b[px])
            v[py] = minOf(v[py], v[px])
        }
    }
    for (i in 0 until m) {
        var (a, b) = readInts()
        unite(a - 1, n1 + b - 1)
    }
    var ans = 0
    for (i in 0 until n1 + n2) {
        if (get(i) == i && b[i]) {
            ans += v[i]
        }
    }
    println(ans)
}