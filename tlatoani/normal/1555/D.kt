import kotlin.math.min

fun main() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }
    val s = " " + readLine()!!
    val sums = Array(2) { Array(3) { IntArray(n + 1) } }
    for (j in 1..n) {
        for (k in 0..1) {
            for (x in 0..2) {
                sums[k][x][j] = sums[k][x][j - 1] + 1
            }
        }
        sums[0][("abc".indexOf(s[j]) + j) % 3][j]--
        sums[1][("cba".indexOf(s[j]) + j) % 3][j]--
    }
    val out = StringBuilder()
    repeat(m) {
        val (l, r) = readLine()!!.split(" ").map { it.toInt() }
        var res = n
        for (k in 0..1) {
            for (x in 0..2) {
                res = min(res, sums[k][x][r] - sums[k][x][l - 1])
            }
        }
        out.appendln(res)
    }
    print(out)
}