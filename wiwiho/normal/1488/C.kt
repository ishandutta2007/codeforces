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

    var T = readInt()
    while(T-- > 0) {

        var (n, x, y) = readInts(3)
        if(x > y){
            x = y.also {y = x}
        }

        var ans = 1000000000
        for (i in x until y) {
            val ax = min(i - x + (if (x - 1 > 0) i - 1 else 0), x - 1 + if (i - x > 0) i - 1 else 0)
            val ay = min(y - i - 1 + (if (n - y > 0) n - i - 1 else 0), n - y + (if (y - i - 1 > 0) n - i - 1 else 0))
//            println("$i $ax $ay")
            ans = min(ans, max(ax, ay))
        }
        println(ans)

    }

}