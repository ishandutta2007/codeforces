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
        var ans = 0L
        var (x, y) = readll()
        for (j in 0 until 9) x *= 10
        for (j in 0 until 9) {
            x /= 10
            var tmp = y / x
            ans = ans + tmp
            y %= x
        }
        println(ans + y)
    }
}