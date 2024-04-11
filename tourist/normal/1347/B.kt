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
        var (a1, b1) = readInts()
        var (a2, b2) = readInts()
        if (a1 > b1) {
            a1 = b1.also{ b1 = a1 }
        }
        if (a2 > b2) {
            a2 = b2.also{ b2 = a2 }
        }
        println(if (b1 == b2 && a1 + a2 == b1) "Yes" else "No")
    }
}