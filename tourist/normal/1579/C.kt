fun main() {
    val t = readInt()
    repeat(t) {
        val (n, m, k) = readInts()
        val a = Array(n) { readLn() }
        val marked = Array(n) { BooleanArray(m) }
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (a[i][j] == '*') {
                    var d = 0
                    while (i - d - 1 >= 0 && j - d - 1 >= 0 && j + d + 1 < m) {
                        if (a[i - d - 1][j - d - 1] == '.') {
                            break
                        }
                        if (a[i - d - 1][j + d + 1] == '.') {
                            break
                        }
                        d += 1
                    }
                    if (d >= k) {
                        for (x in 0..d) {
                            marked[i - x][j - x] = true
                            marked[i - x][j + x] = true
                        }
                    }
                }
            }
        }
        val res = (0 until n).all { i ->
            (0 until m).all { j ->
                a[i][j] == '.' || marked[i][j]
            }
        }
        println(if (res) "YES" else "NO")
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