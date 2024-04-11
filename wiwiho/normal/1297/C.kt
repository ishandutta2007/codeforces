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

        val n = getInt()

        val a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

        var mx = 0
        var mn = 10000000
        for(i in a){
            if(i > 0){
                mx += i
                mn = min(mn, i)
            }
        }
//        System.err.println(mn)

        var ans = -1

        for(i in 0 until n){
            if(a[i] >= 0)continue
            if(ans == -1 || mx + a[ans] < mx + a[i]) ans = i
        }


        val t = MutableList(n) {0}
        for(i in 0 until n) {
            if(a[i] > 0 || i == ans) t[i] = 1
        }

        if(ans == -1 || mx + a[ans] < mx - mn){
            if(ans != -1) t[ans] = 0
            for(i in 0 until n){
                if(a[i] == mn){
                    t[i] = 0
                    break
                }
            }
        }

        var sum = 0
        t.forEachIndexed{i, v -> if(v == 1) sum += a[i]}

        println(sum)
        t.forEach{print(it)}
        println()

    }

}