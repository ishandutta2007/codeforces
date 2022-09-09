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
        var (n,k,x,y)=readInts()
        var a=ArrayList(readInts().sorted())
        var hi=0;var cnt=0;var sum=0L
        for(i in a)sum+=i
        var ans=n.toLong()*x
        for(i in n-1 downTo 0){
            if(sum<=k.toLong()*n){
                ans=min(ans,cnt.toLong()*x+y)
            }
            sum-=a[i]
            cnt++
            if(a[i]>k)hi++
        }
        ans=min(ans,hi.toLong()*x)
        printLine("$ans")
    }
    output()
}