fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val b = Array(n) { IntArray(m) }
    val a = Array(n) { readLine()!!.split(" ").map { it.toInt() } }
    val out = StringBuilder()
    for (y in 1 until n) {
        for (x in 1 until m) {
            if (a[y - 1][x - 1] and a[y][x - 1] and a[y - 1][x] and a[y][x] == 1) {
                b[y - 1][x - 1] = 1
                b[y][x - 1] = 1
                b[y - 1][x] = 1
                b[y][x] = 1
                out.appendln("$y $x")
            }
        }
    }
    if ((0 until n).all { y -> (0 until m).all { x -> b[y][x] == a[y][x] } }) {
        println(out.count { it == '\n' })
        print(out)
    } else {
        println(-1)
    }
}