import java.util.*
import kotlin.math.*

fun Solve() {
    val (n, m) = readLine()!!.split(" ").map{ it.toInt() }
    val a = IntArray(n)
    val u = IntArray(m)
    val v = IntArray(m)
    val w = IntArray(m)
    for (i in 0 until m) {
        var (u_, v_, w_) = readLine()!!.split(" ").map{ it.toInt() }
        u[i] = u_ - 1
        v[i] = v_ - 1
        w[i] = w_
        if (w[i] > a[u[i]]) {
            a[u[i]] = w[i]
        }
        if (w[i] > a[v[i]]) {
            a[v[i]] = w[i]
        }
    }
    for (i in 0 until m) {
        var g = min(a[u[i]], a[v[i]])
        if (g != w[i]) {
            println("NO")
            return
        }
    }
    println("YES")
    for (x in a) {
        print(x.toString() + " ")
    }
    println()
}

fun main() {
    var t = readLine()!!.toInt()
    while (t-- > 0) {
        Solve()
    }
}