import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    val t=readInt()
    repeat(t){
        var n=readInt()
        var ans=ArrayList<Int>()
        if(n%4!=0)printLine("NO")
        else{
            for(i in 2..n/2 step 2){
                ans.add(i)
                ans.add(2*n-i)
            }
            for(i in 1..n/2 step 2){
                ans.add(i)
                ans.add(2*n-i)
            }
            printLine("YES")
            printLine(ans.joinToString(" "))
        }
    }
    output()
}