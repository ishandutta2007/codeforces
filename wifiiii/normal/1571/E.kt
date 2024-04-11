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
    // ()()
    // (())
    // 101010
    var T = readi()
    while(T-- > 0) {
        var n = readi()
        var s = read()
        val t = read()
        var a = ArrayList<Int>()
        for (i in 0..n-4) {
            if(t[i] == '1') a.add(i)
        }
        var ok = 1
        for (i in 1..a.size-1) {
            if(a[i] - a[i-1] == 1 || a[i] - a[i-1] == 3) {
                ok = 0
                break
            }
        }
        if(ok == 0) {
            println(-1)
            continue
        }
        var ans = 0
        var i = 1
        while (i <= a.size) {
            if(i == a.size || a[i] - a[i-1] > 3) {
                val p = a[i-1]
                var p1 = 0
                var p2 = 0
                if(s[p] != '(') p1++; if(s[p] != '(') p2++;
                if(s[p+1] != '(') p1++; if(s[p+1] != ')') p2++;
                if(s[p+2] != ')') p1++; if(s[p+2] != '(') p2++;
                if(s[p+3] != ')') p1++; if(s[p+3] != ')') p2++;
                ans += min(p1, p2)
                i = i + 1
            } else {
                var j = i
                while(j < a.size && a[j] - a[j-1] == 2) {
                    j += 1
                }
                for (k in a[i-1]..a[j-1]+2 step 2) {
                    if(s[k] != '(') ans += 1
                    if(s[k+1] != ')') ans += 1
                }
                i = j + 1
            }
        }
        println(ans)
    }
}