fun main() {
    val (n, m) = readInts()
    val a = List(n) { readInts() }
    val b = MutableList(n) { MutableList(m) {0} }
    data class Step(val i: Int, val j: Int)
    val res = mutableListOf<Step>()
    for (i in 0..n-2) {
        for (j in 0..m-2) {
            if (a[i][j] == 1 && a[i + 1][j] == 1 &&
                    a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
                res.add(Step(i, j))
                b[i][j] = 1
                b[i][j + 1] = 1
                b[i + 1][j] = 1
                b[i + 1][j + 1] = 1
            }
        }
    }
    if (a != b) {
        println(-1)
    } else {
        println(res.size)
        println(res.joinToString("\n") { "${it.i + 1} ${it.j + 1}"})
    }
}

private fun readInt() = readLine()!!.toInt()
private fun readInts() = readLine()!!.split(" ").map {it.toInt()}