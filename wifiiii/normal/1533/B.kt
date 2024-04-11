import java.lang.Math.max
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
        var a = readii()
        a.sortedBy { it }
        var ok = false
        for (i in 1..n-1) {
            if((a[i] - a[i-1]) % 2 == 0) {
                ok = true
                break
            }
        }
        if(ok) println("YES")
        else println("NO")
    }
}