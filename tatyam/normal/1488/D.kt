import kotlin.math.*
import java.util.*

val sc = Scanner(System.`in`)
val INF = 0x3fffffff

fun solve() {
    var n = sc.nextLong()
    var s = sc.nextLong()
    if (n > 100) {
        s -= n - 100
        n = 100
    }
    fun check(a: Long): Boolean {
        var a = a
        var s = s
        for (i in 0 until n) {
            s -= a
            a = (a + 1) / 2
            if (s < 0) return false
        }
        return true
    }
    var ok = 1L
    var ng = s + 1
    while(ng - ok > 1) {
        val cen = (ok + ng) / 2
        if (check(cen)) ok = cen
        else ng = cen
    }
    println(ok)
}
fun main() {
    val t = sc.nextInt()
    for (i in 0 until t) solve()
}