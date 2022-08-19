private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main(args: Array<String>) {
    var n = readInt()
    var a = readLongs()
    var b = Array<Pair<Int, Long>>(n, {i -> Pair(0, 0)})
    for (i in 0..n-1) {
        var aux = a[i]
        var cnt = 0
        while (aux % 3 == 0L) {
            ++cnt
            aux /= 3
        }
        b[i] = Pair(cnt, a[i])
    }
    b.sortWith(compareBy({-it.first}, {it.second}))
    var res = Array<String>(n, {i -> b[i].second.toString()})
    println(res.joinToString(" "))
}