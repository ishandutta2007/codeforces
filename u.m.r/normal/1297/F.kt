import java.io.*
import java.util.*

val MOD = 1000000007
val SZ = 1 shl 18
val INF = (1e18).toLong()
 
fun add(a: Int, b: Int) = (a + b) % MOD // from tourist :o
fun sub(a: Int, b: Int) = (a - b + MOD) % MOD
fun mul(a: Int, b: Int) = ((a.toLong() * b) % MOD).toInt()
fun min(a: Double, b: Double) = if (a < b) a else b
fun max(a: Double, b: Double) = if (a > b) a else b
fun min(a: Long, b: Long) = if (a < b) a else b
fun max(a: Long, b: Long) = if (a > b) a else b
fun max(a: Int, b: Int) = if (a > b) a else b
 
private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }
private fun printInts(a: Array<Int>) = println(a.joinToString("\n")) 
private fun bufferOut(block: PrintWriter.() -> Unit) = PrintWriter(System.out).use { block(it) }

fun gcd(a: Int, b: Int): Int {
    return if (a == 0) b else gcd(b % a,a)
}

var zero = 0.toLong();
var one = 1.toLong();
var two = 2.toLong();
var three = 3.toLong();
var four = 4.toLong();
var five = 5.toLong();
fun powmod(aa: Long, bb: Long, mod: Long): Long {
    var ret = one
    var a = aa
    var b = bb
    while (b > zero) {
        if (b % two == one) {
            ret = ret * a % mod
        }
        a = a * a % mod
        b = b / 2
    }
    return ret
}

fun main(args: Array<String>) = bufferOut { readSolveWrite() }

class ev(val idx: Int, val t: Int)

private fun PrintWriter.readSolveWrite() {
    val qqq = readInt()
    repeat(qqq) {
        val (n, m) = readInts()
        var a = Array<ev>(n + 1, {ev(0, 0)})
        var b = Array<Int>(n, {0})
        for (i in 0..n-1) {
            val (x, y) = readInts()
            a[i] = ev(i, x)
            b[i] = y
        }
        a[n] = ev(n, 2000000000 + 10)
        a.sortWith(Comparator { e1, e2 -> e1.t - e2.t })
        var tm = a[0].t
        var ptr = 0
        var ans = 0
        var ret = Array<Int>(n, {0})
        val pq = PriorityQueue<ev>( {x, y -> x.t.compareTo(y.t)} )
        while (tm < 2000000000 + 10) {
            while (a[ptr].t == tm) {
                pq.add(ev(a[ptr].idx, b[a[ptr].idx]))
                ptr++;
            }
            var rm = m
            while (rm > 0 && pq.size > 0) {
                val cur = pq.remove()
                ret[cur.idx] = tm
                ans = max(ans, tm - b[cur.idx])
                rm -= 1
            }
            if (pq.size > 0) {
                tm += 1
            }
            else {
                tm = a[ptr].t
            }
        }
        println(ans)
        println(ret.joinToString(" "))
    }
}

/**
 * Description: Kotlin tips for dummies
 * Source: own
 */
 
/* sorting
 * 1 (ok)
    val a = nextLongs().sorted() // a is mutable list
 * 2 (ok)
    val a = arrayListOf<Long>() // or ArrayList<Long>()
    a.addAll(nextLongs())
    a.sort()
 *.3 (ok)
    val A = nextLongs()
    val a = Array<Long>(n,{0})
    for (i in 0..n-1) a[i] = A[i]
    a.sort()
 * 4 (ok)
    val a = ArrayList(nextLongs())
    a.sort()
 * 5 (NOT ok)
    val a = LongArray(N) // or nextLongs().toLongArray()
    Arrays.sort(a)
 */
/* 2D array
 * val ori = Array(n, {IntArray(n)})
 * val ori = arrayOf(
    intArrayOf(8, 9, 1, 13),
    intArrayOf(3, 12, 7, 5),
    intArrayOf(0, 2, 4, 11),
    intArrayOf(6, 10, 15, 14)
    )
 */
/* printing variables:
 * println("${l+1} and $r")
 * print d to 8 decimal places: String.format("%.8g%n", d)
 * try to print one stringbuilder instead of multiple prints
 */
/* comparing pairs
    val pq = PriorityQueue<Pair<Long,Int>>({x,y -> x.first.compareTo(y.first)})
    val pq = PriorityQueue<Pair<Long,Int>>(compareBy {it.first})
    val A = arrayListOf(Pair(1,3),Pair(3,2),Pair(2,3))
    val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y -> x.first.compareTo(y.first)})
    sortBy
 */
/* hashmap
    val h = HashMap<String,Int>()
    for (i in 0..n-2) {
        val w = s.substring(i,i+2)
        val c = h.getOrElse(w){0}
        h.put(w,c+1)
    }
 */
/* basically switch, can be used as expression
    when (x) {
        0,1 -> print("x <= 1")
        2 -> print("x == 2")
        else -> { // Note the block
            print("x is neither 1 nor 2")
        }
    }
*/
// swap : a = b.also { b = a }
// arraylist remove element at index: removeAt, not remove ...
// lower bound: use .binarySearch()
 
// fun next() = readLine()!!
// fun nextInt() = next().toInt()
// fun nextLong() = next().toLong()
// fun nextInts() = next().split(" ").map { it.toInt() }
// fun nextLongs() = next().split(" ").map { it.toLong() }