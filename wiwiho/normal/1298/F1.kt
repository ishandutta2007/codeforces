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
    val m = getInt()

    val p = readLine()!!.split(" ").map { it.toInt() }

    val odd = mutableMapOf<Int, Int>()
    val even = mutableMapOf<Int, Int>()

    val pos = p.indexOf(m)

    if(pos % 2 == 0) even[0] = 1
    else odd[0] = 1

    var now = 0
    for (i in pos - 1 downTo 0) {
        if (p[i] < m) now--
        else now++
//        println("$i $now")
        if (i % 2 == 0) even[now] = even.getOrDefault(now, 0) + 1
        else odd[now] = odd.getOrDefault(now, 0) + 1
    }

//    odd.forEach { (k, v) -> println("$k $v") }
//    even.forEach { (k, v) -> println("$k $v") }
    var ans = 0L

    if(pos % 2 == 0){
        ans += even.getOrDefault(0, 0)
        ans += odd.getOrDefault(1, 0)
    }
    else{
        ans += odd.getOrDefault(0, 0)
        ans += even.getOrDefault(1, 0)
    }

    now = 0
    for (i in pos + 1 until n) {
        if(p[i] < m) now--
        else now++
//        println("$i $now")

        if(i % 2 == 0){
            ans += even.getOrDefault(-now, 0)
            ans += odd.getOrDefault(1 - now, 0)
        }
        else{
            ans += odd.getOrDefault(-now, 0)
            ans += even.getOrDefault(1 - now, 0)
        }
    }

    println(ans)

}