import java.io.*

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

private fun PrintWriter.readSolveWrite() {
    val q = readInt()
    for (qqq in 1..q) {
        val (n, k) = readInts()
        val E = Array(n + 1, {HashSet<Int>()})
        for (i in 1..n-1) {
            val (x, y) = readInts()
            E[x].add(y)
            E[y].add(x)
        }
        val deg = Array<Int>(n + 1, {0})
        val p = ArrayList<Int>()
        for (i in 1..n) {
            deg[i] = E[i].size
            if (deg[i] == 1) {
                p.add(i)
            }
        }
        var pq = p.size
        if (k > pq) {
            println("No");
            continue
        }
        if (k == pq) {
            println("Yes");
            println(n)
            println((1..n).joinToString(" "))
            continue
        }
        if (k == 1) {
            println("Yes")
            println("1")
            println("1")
            continue
        }
        // k < pq && k >= 2
        val ans = HashSet<Int>()
        for (i in 1..n) {
            ans.add(i)
        }
        val cnt = pq - k
        for (i in 0..cnt-1){
            var x = p[i]
            // println(p.joinToString("=="))
            while (E[x].size == 1) {
                ans.remove(x)
                val y = E[x].elementAt(0)
                E[x].remove(y)
                E[y].remove(x)
                if (E[y].size == 1) {
                    x = y
                }
            }
        }
        println("Yes")
        println(ans.size)
        println(ans.joinToString(" "))
    }
}
 
class Evt(val i: Int, val p: Int, val d: Int)
 
private fun solveEvents(n: Int, es: ArrayList<Evt>): IntArray? {
    es.sortWith(Comparator { e1, e2 ->
        when {
            e1.p < e2.p -> -1
            e1.p > e2.p -> 1
            else -> e2.d - e1.d
        }
    })
    var cnt = 0
    val r = IntArray(n)
    var cur = 1
    var cc = 0
    for (e in es) {
        cnt += e.d
        when {
            e.d == 1 -> {
                r[e.i] = cur
                cc++
            }
            cnt == 0 && cur == 1 -> {
                cur = 2
                cc = 0
            }
        }
    }
    return if (cc == 0) null else r
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