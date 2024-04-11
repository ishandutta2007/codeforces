import kotlin.math.*
import java.util.*

val sc = Scanner(System.`in`)
val INF = 0x3fffffff

fun solve() {
    val n = sc.nextInt()
    var x = sc.nextInt() - 1
    var y = sc.nextInt() - 1
    if (x > y){
        x = x xor y
        y = x xor y
        x = x xor y
    }
    var l = x + 1
    var r = y
    fun cost1(n: Int, x: Int): Int {
        return n - 1 + min(x, n - 1 - x)
    }
    fun cost(d: Int): Int {
        return max(cost1(d, x), cost1(n - d, y - d))
    }
    while (r - l >= 3){
        val ll = (l + l + r) / 3
        val rr = (r + r + l) / 3
        if (cost(ll) < cost(rr)) r = rr
        else l = ll
    }
    var mn = INF
    for (i in l .. r) {
        if (mn > cost(i)) {
            mn = cost(i)
        }
    }
    println(mn)
}
fun main() {
    val t = sc.nextInt()
    for (i in 0 until t) solve()
}