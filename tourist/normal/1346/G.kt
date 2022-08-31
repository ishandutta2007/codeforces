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
    var (k, n) = readInts()
    var p = readInts()
    var x = readInts()
    if (n == 2) {
        println("YES")
        println("${x[0]} ${p[0]}")
        println("${x[1]} ${p[0]}")
        return
    }
    for (bi in 0 until 3) {
        for (bj in bi + 1 until 3) {
            var diff = x[bj] - x[bi]
            for (period in p) {
                if (diff % period == 0) {
                    var least = x[bi]
                    var first = -1
                    var g = 0
                    for (i in 0 until n) {
                        if ((x[i] - x[bi]) % period == 0) {
                            least = minOf(least, x[i])
                            continue
                        }
                        if (first == -1) {
                            first = x[i]
                        } else {
                            var h = x[i] - first
                            while (g > 0 && h > 0) {
                                if (g > h) {
                                    g %= h
                                } else {
                                    h %= g
                                }
                            }
                            g = g + h
                        }
                    }
                    for (v in p) {
                        if (g % v == 0) {
                            println("YES")
                            println("${least} ${period}")
                            println("${maxOf(first, 1)} ${v}")
                            return
                        }
                    }
                }
            }
        }
    }
    println("NO")
}