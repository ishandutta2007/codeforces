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
    var t = readInt()
    for (qq in 0 until t) {
        var (n, k) = readInts()
        var s = readLn()
        var cc = s.count {id -> id == '1'}
        var a = IntArray(n) {1}
        var ptr = 0
        var ans = 0
        while (cc > 0) {
            ans += 1
            a[ptr] = 0
            if (s[ptr] == '1') {
                cc -= 1
                if (cc == 0) {
                    break
                }
            }
            var take = k
            while (take > 0) {
                while (true) {
                    ptr += 1
                    if (ptr == n) {
                        ptr = 0
                    }
                    if (a[ptr] == 1) {
                        break
                    }
                }
                take -= 1
            }
        }
        println(ans)
    }
}