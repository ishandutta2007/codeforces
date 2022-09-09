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
        var (a,b)=readInts()
        if(a>b)a=b.also{b=a}
        var tmp=min(a,b-a)
        var ans=tmp
        b-=2*tmp
        a-=tmp
        var o=min(a,b)/3*3
        ans+=min(a,b)/3*2
        if(a-o>=1&&b-o>=2)ans++
        printLine("$ans")
    }
    output()
}