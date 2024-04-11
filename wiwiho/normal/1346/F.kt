import java.util.*
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

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun lowbit(x: Int): Int {
    return x and -x
}

class BIT(sz: Int) {

    var bit = mutableListOf<Long>()

    init {
        bit = MutableList(sz + 1) {0L}
    }

    fun modify(x: Int, v: Long){
        var tx = x
        while(tx < bit.size){
            bit[tx] += v
            tx += lowbit(tx)
        }
    }

    fun query(x: Int): Long{
        var ans = 0L
        var tx = x
        while(tx > 0){
            ans += bit[tx]
            tx -= lowbit(tx)
        }
        return ans
    }

}

fun main() {

    val n = getInt()
    val m = getInt()
    val q = getInt()

    val a = MutableList(n) { readLine()!!.split(' ').map { it.toLong() }.toMutableList() }

    val bitx = BIT(n)
    val bity = BIT(m)
    val bitxx = BIT(n)
    val bityy = BIT(m)

    for(i in 0 until n){
        for(j in 0 until m){
            bitx.modify(i + 1, a[i][j])
            bity.modify(j + 1, a[i][j])
            bitxx.modify(i + 1, a[i][j] * (i + 1))
            bityy.modify(j + 1, a[i][j] * (j + 1))
        }
    }

    for(i in 0..q){
        if(i != 0){
            val x = getInt()
            val y = getInt()
            val z = getLong()
            bitx.modify(x, -a[x - 1][y - 1] + z)
            bity.modify(y, -a[x - 1][y - 1] + z)
            bitxx.modify(x, (-a[x - 1][y - 1] + z) * x)
            bityy.modify(y, (-a[x - 1][y - 1] + z) * y)
            a[x - 1][y - 1] = z
        }

//        for(i in 1..n) print("${bitx.query(i) - bitx.query(i - 1)} ")
//        println()
//        for(i in 1..n) print("${bitxx.query(i) - bitxx.query(i - 1)} ")
//        println()
//        for(i in 1..m) print("${bity.query(i) - bity.query(i - 1)} ")
//        println()
//        for(i in 1..m) print("${bityy.query(i) - bityy.query(i - 1)} ")
//        println()

        var ans = 0L

        var l = 1
        var r = n
        var t = (bitx.query(n) + 1) / 2
        while(l < r){
            val m = (l + r) / 2
            if(bitx.query(m) >= t) r = m
            else l = m + 1
        }

//        println("test x $l ${bitx.query(l) * l - bitxx.query(l) + (bitxx.query(n) - bitxx.query(l)) - (bitx.query(n) - bitx.query(l)) * l}")
        ans += bitx.query(l) * l - bitxx.query(l) + (bitxx.query(n) - bitxx.query(l)) - (bitx.query(n) - bitx.query(l)) * l

        l = 1
        r = m
        t = (bity.query(m) + 1) / 2
        while(l < r){
            val m = (l + r) / 2
            if(bity.query(m) >= t) r = m
            else l = m + 1
        }

//        println("test y $l ${bity.query(l) * l - bityy.query(l) + (bityy.query(m) - bityy.query(l)) -  (bity.query(m) - bity.query(l)) * l}")
        ans += bity.query(l) * l - bityy.query(l) + (bityy.query(m) - bityy.query(l)) -  (bity.query(m) - bity.query(l)) * l

        print("$ans ")

    }
    println()

}