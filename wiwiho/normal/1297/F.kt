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

fun <T, U> mp(t : T, u : U) = Pair(t, u)

typealias ll = Long
typealias pii = Pair<Int, Int>
typealias pll = Pair<ll, ll>

val MOD = 1000000007L
val MAX = 2147483647L

fun check(e : TreeMap<Int, MutableList<pii>>, n : Int, m : Int, mx : Int): Boolean {

    return true
}

fun main() {

    var T = getInt()

    while(T-- > 0){

        val n = getInt()
        val m = getInt()

        val e = TreeMap<Int, MutableList<pii>>()
        for(i in 0 until n){
            val a = getInt()
            val b = getInt()
            if(!e.containsKey(a)) e[a] = MutableList(0) {mp(0, 0)}
            e[a]!!.add(mp(b, i))
        }

        val ans = MutableList(n) {0}
        val pq = PriorityQueue<pii>(compareBy {it.first})
        var time = 1
        var cnt = 0
        var t = 0
        for(i in e.entries) {
            while(!pq.isEmpty() && time < i.key){
//                System.err.println("$time ${pq.peek()}")
                ans[pq.peek().second] = time
                t = max(t, time - pq.peek().first)
                pq.poll()
                cnt++
                if(cnt == m){
                    time++
                    cnt = 0
                }
            }
            for(j in i.value) pq.add(j)
            if(i.key > time){
                time = i.key
                cnt = 0
            }
        }
        while(!pq.isEmpty()){
//            System.err.println("$time ${pq.peek()}")
            ans[pq.peek().second] = time
            t = max(t, time - pq.peek().first)
            pq.poll()
            cnt++
            if(cnt == m){
                time++
                cnt = 0
            }
        }

        println(t)
        printv(ans)
    }

}