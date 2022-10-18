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

    while(T-- > 0){

        var n = getInt()

        if(n <= 999) {
            println(n)
            continue
        }

        n /= 100
        var t = n % 10
        n /= 10

        if(n <= 999) {
            if(t >= 5) n++
            if(n > 999) println("1M")
            else println("${n}K")
            continue
        }

        n /= 100
        t = n % 10
        n /= 10

        if(t >= 5) n++
        println("${n}M")

    }

}