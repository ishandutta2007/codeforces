private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        var (n, k) = readInts()
        var a = readInts()
        var b = Array<Pair<Int, Int>>(n, {i -> Pair(a[i], i)})
        b.sortWith(compareBy({it.first}, {it.second}))
        var delta = IntArray(n + 1)
        for (id in n-2 downTo 0) {
            var i = b[id].second
            var j = b[id + 1].second
            var limit = minOf(a[j] - a[i] - 1, k / (id + 1))
            delta[0] += limit
            delta[id + 1] -= limit
            k -= limit * (id + 1)
            if (limit < a[j] - a[i] - 1 && k > 0) {
                delta[id + 1 - k] += 1
                delta[id + 1] -= 1
                k = 0
            }
        }
        delta[0] += k / n
        delta[n] -= k / n
        k %= n
        if (k > 0) {
            delta[n - k] += 1
            delta[n] -= 1
        }
        var res = IntArray(n)
        for (i in 0 until n) {
            res[b[i].second] = delta[i]
            delta[i + 1] += delta[i]
        }
        println(res.joinToString(" "))
    }
}