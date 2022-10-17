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
        var s = read()
        var ans = 0
        var last = 'a'
        for(c in s) {
            if(c == 'w') {
                ans += 1
                last = 'w'
            }
            else if(c == 'v') {
                if(last == 'v') {
                    ans += 1
                    last = 'a'
                } else {
                    last = 'v'
                }
            }
        }
        println(ans)
    }
}