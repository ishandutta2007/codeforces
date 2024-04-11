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

class Node{
    var v = 0L
    var l = -1
    var r = -1
    var tag = 0L
    var sz = 1
    fun rv(): Long {
        return v + tag * sz
    }
}

var st = mutableListOf<Node>()
var ts = 0

fun build(l: Int, r: Int): Int {
    val id = ts++
    st[id].sz = r - l + 1
    if(l == r) return id
    val m = (l + r) / 2
    st[id].l = build(l, m)
    st[id].r = build(m + 1, r)
    return id
}

fun modify(l: Int, r: Int, v: Long, L: Int, R: Int, id: Int) {
    if(l == L && r == R){
        st[id].tag += v
        return
    }
    val M = (L + R) / 2
    if(r <= M) modify(l, r, v, L, M, st[id].l)
    else if(l > M) modify(l, r, v, M + 1, R, st[id].r)
    else{
        modify(l, M, v, L, M, st[id].l)
        modify(M + 1, r, v, M + 1, R, st[id].r)
    }
    st[id].v = st[st[id].l].rv() + st[st[id].r].rv()
}

fun push(id: Int) {
    st[st[id].l].tag += st[id].tag
    st[st[id].r].tag += st[id].tag
    st[id].v = st[id].rv()
    st[id].tag = 0
}

fun query(l: Int, r: Int, L: Int, R: Int, id: Int): Long {
    if(l == L && r == R) return st[id].rv()
    push(id)
    val M = (L + R) / 2
    if(r <= M) return query(l, r, L, M, st[id].l)
    else if(l > M) return query(l, r, M + 1, R, st[id].r)
    else {
        return query(l, M, L, M, st[id].l) + query(M + 1, r, M + 1, R, st[id].r)
    }
}

fun main() {

    val n = readInt()
    val c = MutableList(n + 1) { if (it == 0) 0 else readLong() }

    st = MutableList(2 * n) { Node() }
    build(1, n)

    val p = MutableList(n + 2) {-1}
    val g = MutableList(n + 2) {mutableListOf<Int>()}

    val dq = Stack<Int>()
    dq.push(n + 1)
    for (i in n downTo 1) {
        while (dq.peek() != n + 1 && c[dq.peek()] <= c[i]) dq.pop()
        p[i] = dq.peek()
        g[dq.peek()].add(i)
        dq.push(i)
    }

    val lst = MutableList(n + 2) {0}
    for (i in n + 1 downTo 1) {
        g[i].forEachIndexed { id, v ->
            if (id == g[i].size - 1) lst[v] = lst[i]
            else lst[v] = g[i][id + 1]
        }
    }

    for (i in g[n + 1]) {
        modify(lst[i] + 1, i, c[i], 1, n, 0)
    }

    val qry = MutableList(n + 1) {mutableListOf<pii>()}
    val q = readInt()
    for (i in 0 until q) {
        val (l, r) = readInts(2)
        qry[r].add(mp(l, i))
    }

    val ans = MutableList(q) {0L}
    for (i in n downTo 1) {
        for (j in qry[i]) {
            val l = j.first
            val id = j.second
            ans[id] = query(l, i, 1, n, 0)
        }

        modify(lst[i] + 1, i, -c[i], 1, n, 0)
        for (j in g[i]) {
            modify(lst[j] + 1, j, c[j], 1, n, 0)
        }
    }

    println(ans.joinToString(" "))

}