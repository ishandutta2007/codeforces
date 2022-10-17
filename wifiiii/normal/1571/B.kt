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
    var t = readi()
    while(t-- > 0) {
        var n = readi()
        var (a, va) = readii()
        var (c, vc) = readii()
        var b = readi()
        println(max(va, vc - (c - b)))
    }
}