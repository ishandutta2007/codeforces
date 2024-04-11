import java.lang.Long.max
import kotlin.system.exitProcess

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { exitProcess(0); }

fun main() {
    var t = readi();
    while(t-- > 0) {
        var n = readi()
        var a = readll()
        a = a.sorted()
        var ans: Long = 0
        for(i in 0..n-1) {
            ans = max(ans, (n-i)*a[i]);
        }
        println(ans)
    }
}