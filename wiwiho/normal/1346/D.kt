import java.util.*
import kotlin.math.max
import kotlin.math.min

val readQueue = ArrayDeque<String>()

fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getDouble() = getInput().toDouble()
fun getString() = getInput()
fun getLong() = getInput().toLong()

fun <T> printv(v: Collection<T>) {
    v.forEachIndexed { i, t ->
        if (i != 0) print(" ")
        print(t)
    }
    println()
}

fun <T : Comparable<T>> lsort(v: MutableList<T>) {
    v.sort()
}

fun <T : Comparable<T>> gsort(v: MutableList<T>) {
    v.sortDescending()
}

fun <T, U> mp(t: T, u: U) = Pair(t, u)

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun main() {

    var T = getInt()
    while (T-- > 0) {

        val tmp = readLine()!!.split(' ').map {it.toInt()}
        val n = tmp[0]
        val m = tmp[1]

        val e = mutableListOf<Pair<Int, pii>>()
        val ans = List(n) {0}.toMutableList()
        for(i in 0 until m){
            val tmp = readLine()!!.split(' ').map { it.toInt()}
            val u = tmp[0] - 1
            val v = tmp[1] - 1
            val w = tmp[2]
            ans[u] = max(ans[u], w)
            ans[v] = max(ans[v], w)
            e.add(mp(w, mp(u, v)))
        }

        var pos = true
        for(i in 0 until m){
            if(e[i].first != min(ans[e[i].second.first], ans[e[i].second.second])){
                pos = false
                break
            }
        }

        if(pos){
            println("YES")
            printv(ans)
        }
        else{
            println("NO")
        }

    }
}