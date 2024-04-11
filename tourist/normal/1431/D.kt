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
        var a = readInts()
        var order = ArrayList<Int>()
        for (i in 0 until n) {
            order.add(i)
        }
        order.sortWith(compareBy({a[it]}))
        var ans = IntArray(n)
        var pos = 0
        var i = 0
        while (i < n) {
            pos += a[order[i]]
            if (pos >= n) {
                break
            }
            ans[pos] = order[i] + 1
            i += 1
        }
        pos = 0
        while (i < n) {
            while (pos < n && ans[pos] != 0) {
                pos += 1
            }
            ans[pos] = order[i] + 1
            i += 1
        }
        println(ans.joinToString(" "))
    }
}