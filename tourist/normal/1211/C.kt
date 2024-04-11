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
    var a = ArrayList<Pair<Int, Int>>()
    var ans = 0L
    for (i in 0..n-1) {
        var (x, y, z) = readInts()
        k -= x
        if (k < 0) {
            break
        }
        ans += x.toLong() * z
        a.add(Pair(z, y - x))
    }
    if (k >= 0) {
        a.sortWith(compareBy({it.first},{it.second}))
        for (i in 0..n-1) {
            var take = a[i].second
            if (k < take) take = k
            k -= take
            ans += take.toLong() * a[i].first
        }
    }
    if (k == 0) println(ans)
    else println(-1)
}