import java.util.*

fun main() {
    val t = readInt()
    repeat(t) {
        val n = readInt()
        val a = readInts().map { it - 1 }
        var res = IntArray(n)
        var l = 0
        var r = n
        val seen = BooleanArray(n)
        var ptr = 0
        for (i in n-1 downTo 0) {
            if (a[i] == ptr) {
                res[l++] = a[i]
            } else {
                res[--r] = a[i]
            }
            seen[a[i]] = true
            while (ptr < n && seen[ptr]) {
                ptr += 1
            }
        }
        println(res.joinToString(" ") { "${it + 1}" })
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readDouble() = readLn().toDouble()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun readLongs() = readStrings().map { it.toLong() }
private fun readDoubles() = readStrings().map { it.toDouble() }