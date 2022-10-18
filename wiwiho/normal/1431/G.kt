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

fun main() {

    val n = getInt()
    val k = getInt()

    val a = readLine()!!.split(" ").map { it.toLong() }.sorted()
//    println(a)

    val dp = MutableList(n) { MutableList(n) { 0L } }

    for (len in 1 until n step 2) {
        for (l in 0 until n - len) {
            val r = l + len
            if (len == 1) dp[l][r] = a[r] - a[l]
            else dp[l][r] = a[r] - a[l] + dp[l + 1][r - 1]
            for (m in l + 1 until r step 2) {
                dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r])
            }
        }
    }
//    println(dp)

    val dp2 = MutableList(n + 1) { MutableList(k + 1) { 0L } }
    for (i in 0 until n) {
        if(i != 0){
            for (j in 0..k) {
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j])
            }
        }
        for (j in i + 1 until n step 2) {
            for (t in ((j - i + 1) / 2)..k) {
                dp2[j + 1][t] = max(dp2[j + 1][t], dp2[i][t - (j - i + 1) / 2] + dp[i][j])
            }
        }
    }
//    println(dp2)

    var ans = 0L
    for (i in 0..n) {
        ans = max(ans, dp2[i][k])
    }
    println(ans)

}