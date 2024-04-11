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

var g = MutableList(0) {MutableList(0) {0} }
var p = MutableList(0) {0}
var tmp = MutableList(0) {0}

fun dfs(now : Int, pr : Int) {
    p[now] = pr
    for(i in g[now]){
        if(i != pr) dfs(i, now)
    }
}

fun rm(now : Int) {
    for(i in g[now]) tmp[i]--
}

fun main() {

    var T = getInt()

    while(T-- > 0){

        val n = getInt()
        val k = getInt()

        g = MutableList(n + 1) { MutableList(0) {0} }
        for(i in 0 until n - 1){
            val u = getInt()
            val v = getInt()
            g[u].add(v)
            g[v].add(u)
        }

        if(k == 1) {
            println("Yes\n1\n1")
            continue
        }
        if(k == 2 && n == 2) {
            println("YES\n2\n1 2")
            continue
        }

        var root = 0
        for(i in 1..n) {
            if(g[i].size != 1){
                root = i
                break
            }
        }

//        System.err.println(root)

        p = MutableList(n + 1) {0}
        dfs(root, root)

        val c = MutableList(n + 1) {true}
        c[0] = false
        var cnt = 0
        val q = MutableList(0) {0}
        tmp = MutableList(n + 1) {0}
        for(i in 1..n){
            tmp[i] = g[i].size
            if(g[i].size == 1){
                cnt++
                q.add(i)
            }
        }

        if(k > cnt){
            println("NO")
            continue
        }

        for(i in q){
            if(cnt == k) break

            var v = i
            while(tmp[v] == 1 && v != root) {
                c[v] = false
                rm(v)
                v = p[v]
            }
            if(tmp[v] > 1) cnt--
        }

        println("YES")
        val ans = MutableList(0) {0}
        c.forEachIndexed {i, v -> if(v) ans.add(i)}

        println(ans.size)
        ans.forEach {print("$it ")}
        println()

    }

}