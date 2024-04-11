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

fun ifloor(a: Int, b: Int) = if (a xor b > 0) a / b else (a - b + 1) / b
fun iceil(a: Int, b: Int) = if (a xor b > 0) (a + b - 1) / b else a / b
fun ifloor(a: Long, b: Long) = if (a xor b > 0) a / b else (a - b + 1) / b
fun iceil(a: Long, b: Long) = if (a xor b > 0) (a + b - 1) / b else a / b

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

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

fun check(n: Int, k: Int, x: Int, a: List<Long>, ans: Long): Boolean {
    val pq = PriorityQueue<Long>(compareByDescending { it })
    var now = 0L
    var cnt = 0
    var use = 0
    for (i in 0 until n) {
        pq.add(a[i])
        cnt++
        now += a[i]
        while (now > ans) {
            now -= pq.poll()
            cnt--
            use++
        }
        if(cnt == x) {
            pq.clear()
            now = 0
            cnt = 0
        }
    }
    return use <= k
}

fun main() {

    val n = getInt()
    val k = getInt()
    val x = getInt()

    val a = readLine()!!.split(" ").map { it.toLong() }

    var l = 0L
    var r = 10000000000L
    while(l < r){
        val m = (l + r) / 2
        if(check(n, k, x, a, m)) r = m
        else l = m + 1
    }
    println(l)

}