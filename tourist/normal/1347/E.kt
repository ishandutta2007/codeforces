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
        var n = readInt()
        if (n <= 3) {
            println(-1)
            continue
        }
        var a = ArrayList<Int>()
        var ptr = 0
        while (n - ptr >= 8 || n - ptr == 4 || n - ptr == 5) {
            a.add(ptr + 2)
            a.add(ptr + 4)
            a.add(ptr + 1)
            a.add(ptr + 3)
            ptr += 4
        }
        if (n - ptr == 1) {
            a.add(ptr + 1)
        }
        if (n - ptr >= 6) {
            a.add(ptr + 1)
            a.add(ptr + 4)
            a.add(ptr + 2)
            a.add(ptr + 6)
            a.add(ptr + 3)
            a.add(ptr + 5)
            if (n - ptr == 7) {
                a.add(ptr + 7)
            }
        }
        println(a.joinToString(" "))
    }
}