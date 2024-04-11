import kotlin.math.*
import java.util.*

val sc = Scanner(System.`in`)

fun solve() {
    val n = sc.nextInt()
    val a = List(n) { sc.nextInt() - 1 }
    val idx = MutableList(n) { -1 }
    val pair = List(n) {
        val ans = idx[a[it]]
        idx[a[it]] = it
        ans
    }
    val seg = MutableList(n * 2) { 0 }
    fun set(i: Int, x: Int) {
        var i = i + n
        seg[i] = x
        i /= 2
        while (i > 0) {
            seg[i] = max(seg[i * 2], seg[i * 2 + 1])
            i /= 2
        }
    }
    fun get(l: Int, r: Int): Int {
        var l = l + n
        var r = r + n
        var ans = 0
        while (l < r) {
            if ((l and 1) == 1) {
                if (ans < seg[l]) ans = seg[l]
                l++
            }
            if ((r and 1) == 1) {
                r--
                if (ans < seg[r]) ans = seg[r]
            }
            l /= 2
            r /= 2
        }
        return ans
    }
    for (i in 0 until n) {
        if (pair[i] != -1) set(pair[i], get(pair[i] + 1, i) + 2)
        set(i, 1)
    }
    println(seg[1])
}
fun main() {
    val t = sc.nextInt()
    for (i in 0 until t) solve()
}