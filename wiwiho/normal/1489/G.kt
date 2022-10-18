import java.util.*
import kotlin.math.abs
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

fun ifloor(a: Long, b: Long): Long {
    if (b < 0) return ifloor(-a, -b)
    return if (a xor b > 0) a / b else (a - b + 1) / b
}

fun iceil(a: Long, b: Long): Long {
    if (b < 0) return iceil(-a, -b)
    return if (a xor b > 0) (a + b - 1) / b else a / b
}

fun ifloor(a: Int, b: Int) = ifloor(a.toLong(), b.toLong()).toInt()
fun iceil(a: Int, b: Int) = iceil(a.toLong(), b.toLong()).toInt()

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 1L shl 60

fun <T> List<T>.binarySearchWith(condition: (T) -> Boolean): Int {
    return binarySearch {
        if (condition(it)) 1
        else -1
    }.let { -(it + 1) }
}

fun List<Int>.lowerBound(i: Int): Int {
    return binarySearchWith { it >= i }
}

fun List<Int>.upperBound(i: Int): Int {
    return binarySearchWith { it > i }
}

fun main() {

    val n = getInt()
    val m = getInt()

    val a = mutableListOf(0L)
    readLine()!!.split(" ").map { it.toLong() }.forEach { a.add(it) }

    val st = TreeSet<Int>(compareBy({ a[it] }, {it}))
    for (i in 1..n) st.add(i)

    val g = MutableList(n + 1) { mutableListOf<Pair<Int, Long>>()}
    for (i in 1..m) {
        val u = getInt()
        val v = getInt()
        val w = getLong()
        g[u].add(mp(v, w))
        g[v].add(mp(u, w))
    }

    val vst = MutableList(n + 1) { false }
    val pq = PriorityQueue<Pair<Long, Int>>(compareBy { it.first })
    pq.add(mp(0, 1))
    var ans = 0L
    var mn = MAX
    while(pq.isNotEmpty()) {
        val now = pq.peek().second
        val d = pq.peek().first
        pq.poll()
        if(vst[now]) continue

        vst[now] = true
        ans += d
        mn = min(mn, a[now])
        st.remove(now)
        if(st.isNotEmpty()) {
            val it = st.iterator()
            val mnid = it.next()
            pq.add(mp(mn + a[mnid], mnid))
        }
        for (i in g[now]) {
            if(vst[i.first]) continue
            pq.add(mp(i.second, i.first))
        }
    }

    println(ans)

}