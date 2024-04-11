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
        var (a1,b1)=readInts()
        var (a2,b2)=readInts()
        if(a1>b1)a1=b1.also{b1=a1}
        if(a2>b2)a2=b2.also{b2=a2}
        if(b1==b2&&a1+a2==b1)printLine("YES")
        else printLine("NO")
    }
    output()
}