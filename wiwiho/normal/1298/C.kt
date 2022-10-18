import java.util.*

val readQueue = ArrayDeque<String>()

fun getInput(): String{
    if(readQueue.isEmpty()) readLine()?.split(' ', '\n')?.let { readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt(): Int{
    return getInput().toInt()
}

fun main(){

    val n = readLine()!!.toInt()
    val s = readLine()!!

    var x = 0
    var ans = 0
    s.forEach {
        if (it != 'x') {
            x = 0
            return@forEach
        }
        if (x >= 2) ans++
        else x++
    }

    println(ans)

}