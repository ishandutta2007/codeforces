import java.lang.Math.*
import java.lang.reflect.Array
import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

fun main() {
    var (n, m) = readii()
    var cnt = Array(n) { IntArray(n) }
    var sx = IntArray(n)
    var sy = IntArray(n)
    var (x, y) = readii()
    --x
    --y
    for (i in 0..m-2) {
        var (l, r) = readii()
        --l
        --r
        sx[l] += 1;
        sy[r] += 1
        cnt[l][r] += 1
    }
    var ans = 1
    for (i in 0..n-1) {
        for (j in 0..n-1) {
            if(i == j) continue
            if (i == x && j == y) {

            } else if (i == x || j == y) {
                ans = max(ans, cnt[i][j] + 1)
            } else {
                ans = max(ans, sx[i] + sy[j] - cnt[i][j] + 1)
            }
        }
    }
    println(ans)
}