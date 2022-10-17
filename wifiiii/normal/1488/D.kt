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
        var (x, s) = readll()
        var lo = 1L
        var hi = s
        while(lo < hi) {
            val mid = (1 + lo + hi) / 2
            var res = x
            var cur = mid
            var sum = 0L
            while(res > 0) {
                res -= 1
                sum += cur
                cur = (cur + 1) / 2
                if(sum > s) break
                if(cur == 1L) {
                    sum += res
                    break
                }
            }
            if(sum > s) hi = mid - 1;
            else lo = mid;
        }
        println(lo)
    }
}