import java.lang.Math.max
import java.util.*

private fun read() = readLine()!!
private fun readi() = read().toInt()
private fun reads() = read().split(" ")
private fun readii() = reads().map {it.toInt()}
private fun readl() = read().toLong()
private fun readll() = reads().map {it.toLong()}
private fun exit() { kotlin.system.exitProcess(0); }

val pre = IntArray(200005)
val suf = IntArray(200005)
fun main() {
    val n = readi()
    var a = readii() // n
    var b = readii() // n + 1
    a = a.sortedBy{ it }
    b = b.sortedBy{ it }
    pre[0] = -2000000000
    for(i in 1..n) {
        pre[i] = max(pre[i-1], b[i-1]-a[i-1])
    }
    suf[n+1] = -2000000000
    for(i in n downTo 1) {
        suf[i] = max(suf[i+1], b[i]-a[i-1])
    }
    var m = readi()
    var queries = readii()
    var ans = ArrayList<Int>();
    for(q in queries) {
        var lo = 0
        var hi = n
        while(lo < hi) {
            val mid = (lo + hi) / 2
            if(a[mid] >= q) {
                hi = mid
            } else {
                lo = mid + 1
            }
        }
        ans.add(max(max(pre[lo], suf[lo+1]), b[lo]-q))
    }
    println(ans.joinToString(" "))
}

/*

# input
var n = readi()
var (n, m) = readii();
var a = readii()
var a = Array(n) {read()}
var a = Array(n) {readii()}

# output
println(n)
println("${n} ${m}")
a.forEach{x -> print("$x ")};
println(a.joinToString(" "))

# for-loop
for (i in 1..n) {
    println(i)
}
for (i in n downTo 0) {
    println(i)
}
for (i in a) { // a is xxxArray/ArrayList<xxx>
    println(i)
}

# while-loop
while(l < r) {
    println("${l} ${r}")
    ++l; --r;
}

# string
var str = "aaaaa"
var str = readLine()!!
var s = str.substring(0, 1) + str.substring(1, 2) + str.substring(2, 3)
var sbuilder = StringBuilder(str)

# function
fun f(a: Int, b: Int) : Int {
    return a + b;
}

# collections
ArrayList
HashMap
HashSet
TreeSet : lower(), higher(), equals(), size, add(), remove(), first(), last()
TreeMap

# Comparator
// TreeSet
val cmp =  Comparator<Int> { a, b ->
    when {
        (a > b) -> -1
        (a < b) -> 1
        else -> 0
    }
}
var s = TreeSet<Int>(cmp);

// custom class
class pair(val a: Int, var b: Int): Comparable<pair> {
    override fun compareTo(other: pair): Int {
        if(this.a != other.a) {
            return other.a - this.a
        }
        return other.b - this.b
    }
}
// pair
class pair(val a: Int, var b: Int): Comparable<pair> {
    override fun compareTo(other: pair): Int {
        if(this.a != other.a) {
            return compareValues(this.a, other.a);
        }
        return compareValues(this.b, other.b);
    }
}

# Array
IntArray(n), LongArray(n), BooleanArray(n), ...
var arr = arrayOf(1, 2, 3);
var arr = intArrayOf(1, 2, 3);
// 2d-array
public fun array2dOfInt(n: Int, m: Int): Array<IntArray>
    = Array(n) { IntArray(m) }
public fun array2dOfLong(n: Int, m: Int): Array<LongArray>
    = Array(n) { LongArray(m) }

# Typecasting
var a = 123 as Long / 123.toLong()

# assert
DO NOT use assert
use check instead

# random
var randomValue = (0..10).random()
var randomValues = List(10) { (0..10).random() } // List
var randomValues2 = IntArray(10) { (0..10).random() } // IntArray
var randomValues3 = List(10) { (0..10).random() } as ArrayList<Int> // ArrayList

# higher-order function

# some trick
// swap two number
a = b.apply{b = a}

# some template

// segment tree (range add, point max)
var mx = IntArray(100005 shl 2)
fun update(p: Int, v: Int, l: Int, r: Int, rt: Int) {
    if(l == r) {
        mx[rt] = max(mx[rt], v)
        return
    }
    val m = (l + r) / 2
    if(p <= m) update(p, v, l, m, rt shl 1)
    else update(p, v, m + 1, r, (rt shl 1) or 1)
    mx[rt] = max(mx[rt shl 1], mx[(rt shl 1) or 1])
}
fun query(L: Int, R: Int, l: Int, r: Int, rt: Int): Int {
    if(L <= l && r <= R) return mx[rt]
    val m = (l + r) / 2
    var ret = 0
    if(L <= m) ret = max(ret, query(L, R, l, m, rt shl 1))
    if(m < R) ret = max(ret, query(L, R, m + 1, r, (rt shl 1) or 1))
    return ret
}

// segment tree (range add, range sum)
val maxn = 100005;
var sum = LongArray(maxn shl 2);
var lz = LongArray(maxn shl 2);
fun update(L: Int, R: Int, v: Long, l: Int, r: Int, rt: Int) {
    if(L <= l && r <= R) {
        sum[rt] += v * (r - l + 1);
        lz[rt] += v;
        return;
    }
    val m = (l + r) shr 1;
    if(lz[rt] != 0L) {
        lz[rt shl 1] += lz[rt];
        lz[rt shl 1 or 1] += lz[rt];
        sum[rt shl 1] += lz[rt] * (m - l + 1);
        sum[rt shl 1 or 1] += lz[rt] * (r - m);
        lz[rt] = 0;
    }
    if(L <= m) update(L, R, v, l, m, rt shl 1);
    if(m < R) update(L, R, v, m+1, r, rt shl 1 or 1);
    sum[rt] = sum[rt shl 1] + sum[rt shl 1 or 1];
}
fun query(L: Int, R: Int, l: Int, r: Int, rt: Int): Long {
    if(L <= l && r <= R) return sum[rt];
    val m = (l + r) shr 1;
    if(lz[rt] != 0L) {
        lz[rt shl 1] += lz[rt];
        lz[rt shl 1 or 1] += lz[rt];
        sum[rt shl 1] += lz[rt] * (m - l + 1);
        sum[rt shl 1 or 1] += lz[rt] * (r - m);
        lz[rt] = 0;
    }
    var ret: Long = 0;
    if(L <= m) ret += query(L, R, l, m, rt shl 1);
    if(m < R) ret += query(L, R, m+1, r, rt shl 1 or 1);
    return ret;
}

 */