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
        var a=LinkedList(readInts())
        var ans=0L
        while(a.size>0){
            var x=a.remove()
            while(a.size>0&&(x<0)==(a.first()<0))x=max(x,a.remove())
            ans+=x
        }
        printLine("$ans")
    }
    output()
}