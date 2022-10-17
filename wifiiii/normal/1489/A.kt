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
    var n = readi()
    var a = readii()
    var s = HashSet<Int>()
    var ans = Vector<Int>()
    for (i in n-1 downTo 0) {
        val x = a[i]
        if(!s.contains(x)) {
            s.add(x)
            ans.add(x)
        }
    }
    println(ans.size)
    ans.reverse()
    for (i in ans) {
        print("$i ")
    }
}