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
    val a = readLine()?.split(" ")!!.map {it.toInt()}

    val s = mutableSetOf<Int>()
    val ans = mutableListOf<Int>()
    for (i in n - 1 downTo 0){
        if(!s.contains(a[i])){
            ans.add(a[i])
            s.add(a[i]);
        }
    }

    ans.reverse()
    println("${ans.size}")
    ans.forEach {print("$it ")}
    println()

}