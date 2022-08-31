private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var n = readInt()
    var a = readInts()
    for (i in 0..n-1) {
        var j = 0
        var k = 0
        while (j < n && a[j] >= a[i]) j++
        while (k < n && a[k] <= a[i]) k++
        if (j < n && k < n) {
            println("${j+1} ${i+1} ${k+1}")
            return
        }
    }
    println("-1 -1 -1")
}