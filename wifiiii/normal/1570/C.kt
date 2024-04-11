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
    val n = readi()
    val a = readii()
    var ord = IntArray(n)
    for (i in 0..n-1) {
        ord[i] = i+1
    }
    var sorted = ord.sortedBy { -a[it-1] }
    var sa = a.sorted().reversed()
    var ans = n
    var cur = 0
    for (i in sa) {
        ans += cur * i
        cur ++
    }
    println(ans)
    println(sorted.joinToString(" "))
}