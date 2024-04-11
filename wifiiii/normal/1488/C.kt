import java.util.*
import kotlin.collections.HashSet
import kotlin.math.abs
import kotlin.math.min
import kotlin.math.max
import kotlin.system.exitProcess

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { exitProcess(0); }

fun main() {
    var t = readi()
    for (i in 0 until t) {
        var (n, x, y) = readii()
        if (x > y) {
            var tmp = x
            x = y
            y = tmp
        }
        var ans = n * 2
        for (i in 1 until n) {
            var dx = min((x - 1) + i - 1, abs(x - i) + (i - 1))
            var dy = min(n - y + n - (i + 1), abs(y - (i + 1)) + (n - (i + 1)))
            ans = min(ans, max(dx, dy))
        }
        println(ans)
    }
}