import java.util.*

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

fun main() {

    var T = getInt()

    while(T-- > 0){

        val n = getInt()

        val e = MutableList(2 * n) {mp(0, 0)}
        for(i in 0 until n) {
            val a = getInt()
            val b = getInt()
            e[2 * i] = mp(a, 1)
            e[2 * i + 1] = mp(b + 1, -1)
        }

        e.sortBy { it.first }

        var ans = -1
        var now = 0
        for(i in 0 until 2 * n){
            now += e[i].second
            if(i != 2 * n - 1 && e[i + 1].first == e[i].first) continue
            if(now == 1){
                ans = e[i].first
                break
            }
        }

        println(ans)

    }

}