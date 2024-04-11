import java.util.*
import kotlin.math.max

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

fun main() {

    val n = getInt()
    val k = getInt()

    val c = readLine()!!.split(' ').map { it.toInt() }
    val ans = MutableList(n) { 0 }

    val use = MutableList(k) { MutableList(5001) { false } }

    for (i in 0 until k) {
        for (j in 0 until n) {
            if (use[i][c[j]] || ans[j] != 0) continue
            use[i][c[j]] = true
            ans[j] = i + 1
            break
        }
    }

    for (i in 0 until n) {
        if (ans[i] != 0) continue
        for (j in 0 until k) {
            if (use[j][c[i]]) continue
            use[j][c[i]] = true
            ans[i] = j + 1
            break
        }
        if (ans[i] == 0) {
            println("NO")
            return
        }
    }

    println("YES")
    println(ans.joinToString(" "))

}