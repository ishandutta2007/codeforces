import java.lang.Math.max
import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

val mod1 = 1000000009
val mod2 = 998244353
val p1 = 13331
val p2 = 131
fun main() {
    fun get(s: String) : Pair<Long,Long> {
        var ret1:Long = 0
        var ret2:Long = 0
        for(c in s) {
            ret1=(ret1*p1+c.toLong())%mod1
            ret2=(ret2*p2+c.toLong())%mod2
        }
        return Pair(ret1,ret2)
    }
    var (n, m) = readii()
    var mp = HashMap<Pair<Long,Long>, Int>()
    while(n-- > 0) {
        var s = read()
        var p = get(s)
        var cnt = 0
        if (mp.containsKey(p)) {
            cnt = mp.get(p)!!;
        }
        mp.put(p, cnt+1)
    }
    var q = readi()
    while(q-- > 0) {
        var st = HashSet<Pair<Long,Long>>()
        var s = read()
        var ans = 0
        for (i in 0..m) {
            var s2 = s.substring(0, i) + s.substring(i+1)
            var p = get(s2)
            if(st.contains(p)) continue
            st.add(p)
            var cnt = 0
            if (mp.containsKey(p)) {
                cnt = mp.get(p)!!;
            }
            ans += cnt
        }
        println(ans)
    }
}