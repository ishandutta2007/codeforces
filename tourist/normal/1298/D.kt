private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var (n, w) = readInts()
    var a = readInts()
    var b = IntArray(n + 1) {it * 0}
    for (i in 0 until n) {
        b[i + 1] = b[i] + a[i]
    }
    var min = b.min()!!
    var max = b.max()!!
    var ans = maxOf(w - (max - min) + 1, 0)
    println(ans)
}