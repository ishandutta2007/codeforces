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
        var s = read()
        var ok = 1
        var ans = '='
        for (i in 0..s.length-1) {
            if(s[i] == '=') {
                continue;
            }
            if(ans == '=' || ans == s[i]) {
                ans = s[i]
            } else {
                ok = 0
            }
        }
        if(ok == 1) println(ans)
        else println('?')
    }
}