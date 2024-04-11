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
        var l = 0
        var r = 1000000000
        for (i in 0..n-1) {
            var (a, b, c) = reads()
            var p = min(a.length,b.length)
            for (i in 0..min(a.length,b.length)-1) {
                if(a[a.length-1-i] != b[b.length-1-i]) {
                    p = i
                    break;
                }
            }
            if(c.equals("1")) {
                r = min(r, p)
            } else {
                l = max(l, p + 1)
            }
        }
        var ans = max(0, r - l + 1)
        if(ans > 0) {
            println(ans)
            var a = Array(r - l + 1) {it + l}
            println(a.joinToString(" "))
        } else {
            println(0)
        }
    }
}