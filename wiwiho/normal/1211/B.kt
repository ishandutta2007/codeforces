import java.util.*

fun main(args: Array<String>){

    val scan = Scanner(System.`in`)

    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }.toMutableList()

    var ans = n - 1
    for(i in n - 2 downTo 0){
        if(a[i] > a[ans]){
            ans = i
        }
    }

    val t = (a[ans] - 1).toLong()
    //System.err.println("$t $ans")
    println("${t * n + ans + 1}")

}