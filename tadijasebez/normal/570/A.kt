import java.util.*
import java.math.*
 
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
    fun best(cnt:IntArray):Int{
        var ans=0
        for(i in 0 until n)
            if(cnt[i]>cnt[ans])ans=i
        return ans;
    }
    var cnt=IntArray(n){0}
    for(i in 0 until m)cnt[best(readInts().toIntArray())]++
    printLine((best(cnt)+1).toString())
    output()
}