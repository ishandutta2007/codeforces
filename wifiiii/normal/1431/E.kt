import java.util.*
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

    var t = readi();
    while(t-- > 0) {
        var n = readi()
        var a = readii()
        var b = readii()
        var ans = 0
        var p = 0
        for(i in 0..n-1) {
            var tmp = 10000000;
            for(j in 0..i) tmp= min(tmp, abs(a[j]-b[j+n-i-1]));
            for(j in 0..n-i-2) tmp = min(tmp,abs(b[j]-a[i+1+j]));
            if(tmp > ans) {
                ans = tmp
                p = i
            }
        }
        for(j in 0..n-1) {
            if(j <= p) print("${j+n-p} ")
            else print("${j-p} ")
        }
        println()
    }
}