import java.util.*
import kotlin.math.max
import kotlin.math.min

val readQueue = ArrayDeque<String>()

fun getInput(): String {
    if (readQueue.isEmpty()) readLine()?.split(' ', '\n')?.let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt(): Int {
    return getInput().toInt()
}


fun main() {

    val n = getInt()
    val k = getInt()

    val a = readLine()!!.split(" ").map { it.toInt() }
    val ans = MutableList(n) {0}
    val b = a.mapIndexed { i, v -> Pair(v, i) }.toMutableList()
    b.sortBy { it.first }
    for(i in 0 until n){
        if(i != 0 && b[i].first == b[i - 1].first) ans[b[i].second] = ans[b[i - 1].second]
        else ans[b[i].second] = i
    }

//    ans.forEach { System.err.print(it) }
//    System.err.println()

    for (i in 1..k){
        var x = getInt() - 1
        var y = getInt() - 1
        if(a[x] == a[y]) continue
//        System.err.println("$x $y")
        if(a[x] < a[y]) x = y.also { y = x }
//        System.err.println("$x $y")
        ans[x]--
    }

    ans.forEach { print("$it ") }
    println()

}