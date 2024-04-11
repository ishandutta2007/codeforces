import java.util.*
import kotlin.collections.HashSet
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

var mx = IntArray(1000010)
fun init(l: Int, r: Int, rt: Int) {
    mx[rt] = 0
    if(l == r) return;
    var m = (l + r) / 2
    init(l, m, rt shl 1)
    init(m + 1, r, (rt shl 1) or 1)
}
fun update(p: Int, v: Int, l: Int, r: Int, rt: Int) {
    if(l == r) {
        mx[rt] = max(mx[rt], v)
        return
    }
    val m = (l + r) / 2
    if(p <= m) update(p, v, l, m, rt shl 1)
    else update(p, v, m + 1, r, (rt shl 1) or 1)
    mx[rt] = max(mx[rt shl 1], mx[(rt shl 1) or 1])
}
fun query(L: Int, R: Int, l: Int, r: Int, rt: Int): Int {
    if(L <= l && r <= R) return mx[rt]
    val m = (l + r) / 2
    var ret = 0
    if(L <= m) ret = max(ret, query(L, R, l, m, rt shl 1))
    if(m < R) ret = max(ret, query(L, R, m + 1, r, (rt shl 1) or 1))
    return ret
}

fun main() {
    var t = readi()
    for (i in 0 until t) {
        var n = readi()
        var a = readii()
        var last_vis = IntArray(n+1)
        init(1, n, 1)
        var ans = 1
        for (i in 1..n) {
            val x = a[i-1]
            if(last_vis[x] != 0) {
                var last = last_vis[x]
                if(last + 1 == i) {
                    ans = max(ans, 2)
                    update(last, 2, 1, n, 1)
                } else {
                    var tmp = query(last + 1, i - 1, 1, n, 1) + 2
                    update(last, tmp, 1, n, 1)
                    ans = max(ans, tmp)
                }
            } else {
                last_vis[x] = i
            }
            update(i, 1, 1, n, 1)
        }
        println(ans)
    }
}