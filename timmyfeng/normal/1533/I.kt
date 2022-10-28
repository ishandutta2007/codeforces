import kotlin.math.*

lateinit var tourists: IntArray
lateinit var balance: IntArray
lateinit var par: IntArray

fun find(u: Int): Int {
    if (par[u] != u) {
        par[u] = find(par[u])
    }
    return par[u]
}

fun unite(u: Int, v: Int) {
    val a = find(u)
    val b = find(v)
    if (a != b) {
        tourists[a] = min(tourists[a], tourists[b])
        balance[a] += balance[b]
        par[b] = a
    }
    --balance[a]
}

fun main() {
    val (n1, n2, m) = readLine()!!.split(" ").map { it.toInt() }
    val k = readLine()!!.split(" ").map { it.toInt() }

    tourists = IntArray(n1 + n2) { if (it < n1) k[it] else Int.MAX_VALUE }
    balance = IntArray(n1 + n2) { 1 }
    par = IntArray(n1 + n2) { it }

    for (i in 0 until m) {
        val (u, v) = readLine()!!.split(" ").map { it.toInt() - 1 }
        unite(u, v + n1)
    }

    var ans = 0
    for (i in 0 until n1 + n2) {
        if (par[i] == i && balance[i] == 1) {
            ans += tourists[i]
        }
    }

    println(ans)
}