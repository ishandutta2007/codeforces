import java.util.*
import kotlin.math.max
import kotlin.math.min

val readQueue = ArrayDeque<String>()

fun getInput(): String{
    if(readQueue.isEmpty()) readLine()?.split(' ', '\n')?.let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt(): Int{
    return getInput().toInt()
}

fun main(){

    val n = getInt()
    val w = getInt()

    var now = 0
    var mx = 0
    var mn = 0
    readLine()!!.split(" ").map { it.toInt() }.forEach {
        now += it
        mx = max(mx, now)
        mn = min(mn, now)
    }

//    System.err.println("$mx $mn")
    println("${max(w + 1 - (mx - mn), 0)}")

}