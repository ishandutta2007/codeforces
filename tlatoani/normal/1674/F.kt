import java.util.*

fun main() {
    val (n, m, q) = readLine()!!.split(" ").map { it.toInt() }
    val desktop = Array(n) { readLine()!!.toCharArray() }
    var amt = desktop.sumBy { it.count { it == '*' } }
    var res = 0
    for (j in 0 until amt) {
        val x = j / n
        val y = j % n
        if (desktop[y][x] == '.') {
            res++
        }
    }
    val out = StringBuilder()
    repeat(q) {
        val (y, x) = readLine()!!.split(" ").map { it.toInt() - 1 }
        val z = (n * x) + y
        if (desktop[y][x] == '.') {
            desktop[y][x] = '*'
            if (z < amt) {
                res--
            }
            if (desktop[amt % n][amt / n] == '.') {
                res++
            }
            amt++
        } else {
            desktop[y][x] = '.'
            if (z < amt) {
                res++
            }
            amt--
            if (desktop[amt % n][amt / n] == '.') {
                res--
            }
        }
        out.appendln(res)
    }
    print(out)
}