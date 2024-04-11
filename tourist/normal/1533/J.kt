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
    val M = 500010
    var n = readInt()
    var x = IntArray(n)
    var y = IntArray(n)
    var at = Array(M) {ArrayList<Int>()}
    for (i in 0 until n) {
        var (a, b) = readInts()
        x[i] = a
        y[i] = b
        at[y[i]].add(i)
    }
    var ans = n
    for (left in 0..1) {
        var p = IntArray(n) {it -> if ((y[it] and 1) == left) 1 else 0}
        var st = IntArray(n)
        var aux = IntArray(n)
        var c = ArrayList<Int>()
        for (yy in 0 until M) {
            for (i in at[yy]) {
                c.add(i)
            }
            c.sortWith(compareBy({x[it]}, {p[it]}))
            var cnt = c.size
            for (i in 0 until cnt) {
                aux[i] = c[i]
            }
            c.clear()
            var sz = 0
            for (id in 0 until cnt) {
                var i = aux[id]
                if (p[i] == 1) {
                    st[sz++] = i
                } else {
                    if (sz > 0) {
                        sz -= 1
                        ans -= 1
                    } else {
                        if (y[i] == yy) {
                            c.add(i)
                        }
                    }
                }
            }
            if (sz > 0 && y[st[sz - 1]] == yy) {
                for (i in 0 until sz) {
                    c.add(st[i])
                }
            }
        }
    }
    println(ans)
}