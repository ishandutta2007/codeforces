import java.util.*
import kotlin.math.*

fun Best(x: LongArray): Long {
    var res: Long = 1000000000000000000
    var pref: Long = 0
    var suff: Long = 0
    var pref_cnt: Long = 0
    var suff_cnt: Long = 0
    for (i in 0 until x.size) {
        suff += x[i] * i
        suff_cnt += x[i]
    }
    for (i in 0 until x.size) {
        suff -= x[i] * i
        suff_cnt -= x[i]
        pref += x[i] * i
        pref_cnt += x[i]
        val cost: Long = i * pref_cnt - pref + suff - i * suff_cnt
        res = min(res, cost)
    }
    return res
}

fun Solve() {
    val (n, m, q) = readLine()!!.split(" ").map{ it.toInt() }
    val a = Array(n, { i -> IntArray(m) })
    for (i in 0 until n) {
        var x = readLine()!!.split(" ").map{ it.toInt() }.toMutableList()
        for (j in 0 until m) {
            a[i][j] = x[j]
        }
    }
    val row = LongArray(n)
    val col = LongArray(m)
    for (i in 0 until n) {
        for (j in 0 until m) {
            row[i] = row[i] + a[i][j]
            col[j] = col[j] + a[i][j]
        }
    }
    print(Best(row) + Best(col))
    print(" ")
    for (i in 0 until q) {
        var (x, y, z) = readLine()!!.split(" ").map{ it.toInt() }
        x -= 1
        y -= 1
        row[x] = row[x] - a[x][y]
        col[y] = col[y] - a[x][y]
        a[x][y] = z
        row[x] = row[x] + a[x][y]
        col[y] = col[y] + a[x][y]
        print(Best(row) + Best(col))
        print(" ")
    }
}

fun main() {
    var t = 1
    while (t-- > 0) {
        Solve()
    }
}