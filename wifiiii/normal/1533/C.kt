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
        var (n, k) = readii()
        var s = read()
        var cnt = 0
        for(c in s) {
            if(c == '1') cnt++;
        }
        var vis = IntArray(n)
        var cur = 0
        var ans = 0
        while(cnt > 0) {
            while(vis[cur]==1) {
                cur++; if(cur==n) cur=0;
            }
            vis[cur]=1;
            ++ans;
            if(s[cur]=='1') cnt--;
            if(cnt == 0) break
            for(i in 0..k-1) {
                ++cur; if(cur==n) cur=0;
                while(vis[cur] == 1) {
                    cur++; if(cur==n) cur=0;
                }
            }
        }
        println(ans)
    }
}