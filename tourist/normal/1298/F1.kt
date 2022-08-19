private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

var fenw = IntArray(0)

fun modify(q: Int, v: Int) {
    var x = q
    while (x < fenw.size) {
        fenw[x] += v
        x = (x or (x + 1))
    }
}

fun get(q: Int) : Int {
    var x = q
    var res = 0
    while (x >= 0) {
        res += fenw[x]
        x = (x and (x + 1)) - 1
    }
    return res
}

fun count(a: IntArray) : Long {
    var n = a.size
    fenw = IntArray(2 * n + 1) {0}
    var s = n
    modify(s, 1)
    var ans: Long = 0L
    a.forEach {
        s += it
        ans += get(s - 1)
        modify(s, 1)
    }
    return ans
}

fun main(args: Array<String>) {
    var (n, m) = readInts()
    var a = readInts()
    var b = IntArray(n) {it -> if (a[it] > m) 1 else -1}
    var c = IntArray(n) {it -> if (a[it] >= m) 1 else -1}
    println(count(c) - count(b))
}