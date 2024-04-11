private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        var n = readInt()
        var a = readInts()
        var s = 0
        for (x in a) {
            s += maxOf(x, 0)
        }
        var t = CharArray(n)
        for (i in 0 until n) {
            t[i] = (if (a[i] > 0) '1' else '0')
        }
        var v = 787788
        var who = -1
        for (i in 0 until n) {
            if (a[i] > 0) {
                if (a[i] < v) {
                    v = a[i]
                    who = i
                }
            }
            if (a[i] < 0) {
                if (-a[i] < v) {
                    v = -a[i]
                    who = i
                }
            }
        }
        t[who] = (if (a[who] > 0) '0' else '1')
        println(s - v)
        println(t.joinToString(""))
    }
}