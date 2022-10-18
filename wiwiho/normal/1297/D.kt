import java.util.*
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

fun <T, U> mp(t : T, u : U) = Pair(t, u)

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun check(b : List<Pair<Long, Int>>, n : Int, k : Long, mx: Long) : Boolean {

    var lst = mx
    var now = k - (mx - b[0].first)

    for(i in 1 until n){
        lst = min(b[i].first + now, lst - 1)
        now -= (lst - b[i].first)
    }

    return now == 0L
}

fun main() {

    var T = getInt()

    while(T-- > 0){

        val n = getInt()
        val k = getLong()

        val a = readLine()!!.split(" ").map {it.toLong()}
        val b = a.mapIndexed { i, v -> mp(v, i)}.sortedByDescending { it.first }

        var l = b[0].first
        var r = b[0].first + k

        while(l < r){
            val m = (l + r) / 2
            if(check(b, n, k, m)) r = m
            else l = m + 1
        }

        val ans = MutableList(n) {0L}

        var lst = l
        var now = k - (l - b[0].first)
        ans[b[0].second] = lst - a[b[0].second]

        for(i in 1 until n){
            lst = min(b[i].first + now, lst - 1)
            ans[b[i].second] = lst - a[b[i].second]
            now -= (lst - b[i].first)
        }

        printv(ans)

    }

}