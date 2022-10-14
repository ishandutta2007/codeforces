import java.io.*
import java.util.*

fun max(a:Int,b:Int) = if (a>b) a else b
fun min(a:Int,b:Int) = if (a<b) a else b

fun main(argv: Array<String>) {
    var tt = readLine()!!.toInt();
    while(tt>0) {
        val a = readLine()!!.split(" ").map { it.toInt() }
        val b = readLine()!!.split(" ").map { it.toInt() }
        
        if(max(a[0], a[1]) == max(b[0], b[1]) && min(a[0], a[1]) + min(b[0], b[1]) == max(a[0], a[1])) println("Yes")
        else println("No")
        tt-=1;
    }
}