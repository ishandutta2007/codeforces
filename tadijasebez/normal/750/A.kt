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
    var (n,k)=readInts()
    var now=5;var ans=0
    var lef=4*60-k
    while(lef>=now){
        lef-=now
        ans++
        now+=5
    }
    printLine("${min(ans,n)}")
    output()
}