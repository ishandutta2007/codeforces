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
    var (n,m)=readInts()
    var now=1;var ans=0L
    var a=readInts()
    for(i in a){
        var len=if(i>=now)i-now else n-now+i
        ans+=len
        now=i
    }
    printLine("$ans")
    output()
}