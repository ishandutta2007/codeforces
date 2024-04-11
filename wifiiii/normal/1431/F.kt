import java.util.*
import kotlin.system.exitProcess

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { exitProcess(0); }

fun main() {
    var (n, k, x) = readii()
    var a = readii()
    var lo = 0L
    var hi = 10000000000L
    while(lo < hi) {
        var mid = (lo + hi) / 2;
        var used = 0
        var sz = 0
        var cur = 0L
        var mp = TreeMap<Int, Int>();
        for(i in a) {
            cur += i
            sz++
            if(mp.contains(i)) {
                mp[i] = mp[i]!! + 1
            } else {
                mp.put(i, 1)
            }
            while(cur > mid) {
                cur -= mp.lastKey()
                if(mp.lastEntry().value == 1) mp.remove(mp.lastKey());
                else mp[mp.lastKey()] = mp[mp.lastKey()]!! - 1
                used += 1
                --sz
            }
            if(sz == x) {
                sz = 0
                cur = 0
                mp.clear()
            }
            if(used > k) break;
        }
        if(used > k) lo = mid + 1;
        else hi = mid;
    }
    println(lo)
}