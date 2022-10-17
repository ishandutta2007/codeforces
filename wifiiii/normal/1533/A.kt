import java.lang.Integer.max
import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

fun main() {
    var t = readi()
    while(t-- > 0) {
        var (n, k) = readii()
        var ans = 0
        for (i in 1..n) {
            var (l, r) = readii()
            if(l <= k && k <= r) {
                ans = max(ans, r - k + 1)
            }
        }
        println(ans)
    }
}