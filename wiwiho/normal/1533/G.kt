import java.util.*
import kotlin.math.*

@JvmField
val INPUT = System.`in`

@JvmField
val OUTPUT = System.out

@JvmField
val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!

@JvmField
var _tokenizer: StringTokenizer = StringTokenizer("")
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

var n = 0
var m = 0
var a = listOf<List<Int>>()

var g = mutableListOf<MutableList<Int>>()
var use = mutableListOf<Boolean>()

val dir = listOf(mp(1, 0), mp(0, 1), mp(-1, 0), mp(0, -1))
var ans = mutableListOf<Int>()
var k = 0
fun dfs(x: Int, y: Int) {
    use[a[x][y]] = true
    ans.add(a[x][y])
    k++
    for (i in dir) {
        val (nx, ny) = listOf(x + i.first, y + i.second)
        if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue
        if (a[nx][ny] == 0 || use[a[nx][ny]]) continue
        g[a[x][y]].add(a[nx][ny])
        dfs(nx, ny)
        ans.add(a[x][y])
    }
}

fun main() {

    var T = readInt()
    owo@while (T-- > 0) {
        n = readInt()
        m = readInt()
        g = MutableList(101) { mutableListOf() }
        use = MutableList(101) { false }
        ans = mutableListOf<Int>()
        k = 0

        a = readLines(n).map { it.split(" ").map { it.toInt() } }
        var rt = -1
        for (i in 0 until n) {
            for (j in 0 until m) {
                if (a[i][j] == 0) continue
                if (rt == -1) {
                    dfs(i, j)
                    rt = a[i][j]
                } else if (!use[a[i][j]]) {
                    println("-1")
                    continue@owo
                }
            }
        }

        val a = MutableList(k) { i -> MutableList(k) { j -> ans[i + j] } }
        println(listOf(k, k).joinToString(" "))
        a.forEach {
            println(it.joinToString(" "))
        }

    }

}