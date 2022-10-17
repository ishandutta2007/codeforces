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
        var b = a.withIndex().sortedBy { it.value }
        var v = ArrayList<Int>(n);
        var vis = ArrayList<Boolean>(n);
        for(i in 1..n) {
            v.add(0)
            vis.add(false)
        }
        var pos = 0
        for(i in b) {
            v[pos] = i.index + 1
            vis[i.index] = true
            pos += i.value
            if(pos >= n) break
        }
        var cur = 0
        for(i in 0..n-1) {
            if(vis[i]) continue;
            while(cur < n && v[cur] != 0) cur++;
            v[cur] = i + 1
        }
        v.reverse()
        for(i in v) print("$i ");
        println()
    }
}