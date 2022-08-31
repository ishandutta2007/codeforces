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
    var (h, w) = readInts()
    var s = Array<String>(h) {""}
    for (i in 0 until h) {
        s[i] = readLn()
    }
    var cnt = LongArray(32)
    var st = IntArray(w + 1)
    var ans = LongArray(5)
    for (mask in 1 until 32) {
        var b = IntArray(w)
        for (i in 0 until h) {
            var sum = 0L
            var sz = 1
            st[0] = -1
            for (j in 0 until w) {
                var c = s[i][j].toInt() - 65
                if ((mask and (1 shl c)) != 0) {
                    b[j] += 1
                } else {
                    b[j] = 0
                }
                while (sz > 1 && b[j] <= b[st[sz - 1]]) {
                    sum -= b[st[sz - 1]] * (st[sz - 1] - st[sz - 2])
                    sz -= 1
                }
                sum += b[j] * (j - st[sz - 1])
                st[sz++] = j
                cnt[mask] += sum
            }
        }
        var old = cnt[mask]
        for (sub in 1 until mask) {
            if ((mask and sub) == sub) {
                cnt[mask] -= cnt[sub]
            }
        }
        var pc = 0
        for (i in 0 until 5) {
            pc += (mask shr i) and 1
        }
        ans[pc - 1] += cnt[mask]
    }
    println(ans.joinToString(" "))
}