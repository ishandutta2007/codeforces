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
    var q = readi()
    while(q-- > 0) {
        var input = readll()
        var n = input[0]
        var a = input[1]
        var b = input[2]
        b = min(b, 2 * a)
        println(n / 2 * b + n % 2 * a)
    }
}