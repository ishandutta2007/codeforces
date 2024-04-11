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

        val n = getLong()
        val k = getLong()
        val x = getLong()
        val y = getLong()

        val pq = PriorityQueue<Long>(n.toInt(), compareByDescending { it })
        var sum = 0L
        readLine()!!.split(' ').map {it.toLong()} .forEach {
            pq.add(it)
            sum += it
        }

        var ans = x * n
        for(i in 0..n){
            if(pq.isEmpty() || pq.peek() <= k) ans = min(ans, i * x)

            var tmp = 0
            if(sum % n > 0) tmp = 1

            if(sum / n > k) ;
            else if(sum / n + tmp > k) ans = min(ans, i * x + y + (sum % n) * x)
            else ans = min(ans, i * x + y)
            if(!pq.isEmpty()) sum -= pq.poll()
        }

        println("$ans")

    }
}