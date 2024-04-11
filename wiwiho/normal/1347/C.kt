import java.util.*

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

    val t = getInput().toInt()

    for(i in 1..t){
        var n = getInput().toInt()
        var tmp = 1
        val ans = mutableListOf<Int>()
        while(n > 0){
            if(n % 10 > 0) ans.add(n % 10 * tmp)
            n /= 10
            tmp *= 10
        }
        println(ans.size)
        printv(ans)
    }

}