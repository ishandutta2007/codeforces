import java.lang.AssertionError
import kotlin.system.exitProcess

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
    var n = readInt()
    var s = Array<String>(2 * n - 2) {""}
    var x = ""
    var y = ""
    for (i in 0 until 2 * n - 2) {
        s[i] = readLn()
        if (s[i].length == n - 1) {
            if (x == "") {
                x = s[i]
            } else {
                y = s[i]
            }
        }
    }
    fun test(w: String) {
        var res = CharArray(2 * n - 2)
        var used = BooleanArray(n)
        for (i in 0 until 2 * n - 2) {
            if (w.startsWith(s[i]) && !used[s[i].length]) {
                res[i] = 'P'
                used[s[i].length] = true
                continue
            }
            if (w.endsWith(s[i])) {
                res[i] = 'S'
                continue
            }
            return
        }
        println(res.joinToString(""))
        exitProcess(0)
    }
    test(x[0] + y)
    test(y[0] + x)
    myAssert(false)
}