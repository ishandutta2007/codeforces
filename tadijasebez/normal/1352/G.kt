import java.util.*
import java.math.*
import kotlin.collections.ArrayList
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
        if(n<4)printLine("-1")
        else{
            var x=ArrayList<Int>()
            var y=ArrayList<Int>()
            for(i in 1..n){
                if(i%2==n%2)x.add(i)
                else y.add(i)
            }
            var ans=ArrayList<Int>()
            for(i in x)ans.add(i)
            ans.add(y[y.size-2])
            ans.add(y[y.size-1])
            for(i in y.size-3 downTo 0)ans.add(y[i])
            printLine(ans.joinToString(" "))
        }
    }
    output()
}