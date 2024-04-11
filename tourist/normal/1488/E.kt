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
        var occ = IntArray(n + 1) {-1}
        var b = ArrayList<Int>()
        for (i in 0 until n) {
            if (occ[a[i]] != -1) {
                b.add(2 * occ[a[i]] + 1)
                if (i > occ[a[i]] + 1) {
                    b.add(2 * occ[a[i]])
                }
            }
            occ[a[i]] = i
        }
        // answer = 1 + length of the longest decreasing subsequence in b
        var u = ArrayList<Int>()
        for (x in b.reversed()) {
            var low = 0
            var high = u.size
            while (low < high) {
                var mid = (low + high) shr 1
                if (x > u[mid]) {
                    low = mid + 1
                } else {
                    high = mid
                }
            }
            if (low == u.size) {
                u.add(x)
            } else {
                u[low] = x
            }
        }
        println(u.size + 1)
    }
}