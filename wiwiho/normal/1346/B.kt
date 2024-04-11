import java.util.*
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

fun <T, U> mp(t : T, u : U) = Pair(t, u)

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun main() {

    var T = getInt()
    while(T-- > 0) {

        val n = getInt()
        val k1 = getInt()
        val k2 = getInt()
        val s = getString()

        var now = 1
        var m = 0
        for(i in 0 until n){

            if(s[i] == '0'){
                now = 1
                continue
            }
            else{
                if(now % 2 == 1) m += min(k1, k2)
                else m += min(k1, k2 - min(k1, k2))
                now++
            }

        }

        println("$m")

    }
}