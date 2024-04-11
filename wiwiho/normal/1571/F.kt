import java.util.*
import kotlin.math.*

@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

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

    var (n, m) = readInts(2)

    val a = mutableListOf(-1)
    val id = mutableListOf(-1)
    var sum = 0
    var day = 1
    val ans = MutableList(n) {-1}
    for (i in 0 until n){
        val (k, t) = readInts(2)
        if(t == 1){
            m -= k
            ans[i] = day
            day += k
        };
        else{
            a.add(k)
            id.add(i)
            sum += k
        }
    }
    if(m < 0){
        println("-1")
        return
    }

    val dp = MutableList(a.size) { MutableList(m + 1) { -1 } }
    dp[0][0] = 0
    for (i in 1 until a.size) {
        for (j in 0..m) {
            if (dp[i - 1][j] != -1) dp[i][j] = j
            if (j - a[i] >= 0 && dp[i - 1][j - a[i]] != -1) {
                dp[i][j] = j - a[i]
            }
        }
    }

    for (i in 0..m) {
        if(dp[a.size - 1][i] == -1) continue
        if(!(i <= iceil(m, 2) && sum - i <= ifloor(m, 2))) continue

        var now = i
        val choose = MutableList(a.size) {false}
        for (j in a.size - 1 downTo 1) {
            if(dp[j][now] != now) choose[j] = true
            now = dp[j][now]
        }

        var t1 = day
        var t2 = day + 1
        for (j in 1 until a.size) {
            if (choose[j]) {
                ans[id[j]] = t1
                t1 += a[j] * 2
            }
            else {
                ans[id[j]] = t2
                t2 += a[j] * 2
            }
        }
        println(ans.joinToString(" "))

        return
    }
    println("-1")

}