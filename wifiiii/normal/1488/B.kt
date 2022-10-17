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
        var (n, k) = readii()
        var s = read()
        var cnt = 0
        var ans = 0
        var res = n / 2
        for (c in s) {
            if(c == '(') {
                cnt += 1
            } else if(c == ')') {
                cnt -= 1
            }
            if(cnt == 0) {
                res -= 1
                ans += 1
            }
        }
        if(res < k) {
            k = res
        }
        ans += k
        println(ans)
    }
}