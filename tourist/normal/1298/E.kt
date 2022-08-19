private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, k) = readInts()
    var r = readInts()
    var order = IntArray(n) {it}.sortedBy {r[it]}
    var ans = IntArray(n)
    var beg = 0
    while (beg < n) {
        var end = beg
        while (end + 1 < n && r[order[end + 1]] == r[order[end]]) {
            end += 1
        }
        for (i in beg..end) {
            ans[order[i]] = beg
        }
        beg = end + 1
    }
    for (i in 1..k) {
        var (x, y) = readInts()
        --x
        --y
        if (r[x] > r[y]) {
            --ans[x]
        }
        if (r[x] < r[y]) {
            --ans[y]
        }
    }
    println(ans.joinToString(" "))
}