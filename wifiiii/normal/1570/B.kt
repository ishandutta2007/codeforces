import java.lang.Math.*
import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

fun main() {
    var a1 = readi()
    var a2 = readi()
    var k1 = readi()
    var k2 = readi()
    var n = readi()
    var lim = (k1 - 1) * a1 + (k2 - 1) * a2
    var mn = max(0, n - lim)
    var mx = 0
    if (k1 > k2) {
        k1 = k2.apply{k2 = k1}
        a1 = a2.apply{a2 = a1}
    }
    var p = min(a1, n / k1)
    n -= p * k1
    mx += p
    p = min(a2, n / k2)
    mx += p
    println("${mn} ${mx}")
}