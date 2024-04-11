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

fun max(a:Pair<Int,Int>,b:Pair<Int,Int>):Pair<Int,Int>{
    if(a.first>b.first||(a.first==b.first&&a.second>b.second))return a
    return b
}
fun main(){
    val t=readInt()
    repeat(t){
        var (n,k)=readInts()
        var a=readInts().toIntArray()
        var cnt=TreeMap<Int,Int>()
        var mx=Pair(0,0)
        for(i in a){
            if(!cnt.containsKey(i%k))cnt.set(i%k,0)
            cnt.set(i%k,cnt[i%k]!!+1)
            if(i%k!=0)mx=max(mx,Pair(cnt[i%k]!!,k-i%k+1))
        }
        var ans=max(0L,mx.first.toLong()-1)*k+mx.second
        printLine("$ans")
        //printLine("${mx.first} ${mx.second}")
    }
    output()
}