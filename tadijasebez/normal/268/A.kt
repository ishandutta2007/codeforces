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
    var n=readInt()
    var cnt=Array(105){0}
    var teams=Array(n){Pair(0,0)}
    for(i in 0 until n){
        var (h,a)=readInts()
        teams[i]=Pair(h,a)
        cnt[a]++
    }
    var ans=0
    for(i in 0 until n){
        ans+=cnt[teams[i].first]
        if(teams[i].second==teams[i].first)ans--
    }
    printLine("$ans")
    output()
}