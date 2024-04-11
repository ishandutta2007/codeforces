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
        var a=readInts().toIntArray()
        var mx=0;for(i in a)mx=max(mx,i)
        var chk=Array(mx+1){false}
        var sum=IntArray(n+1){0}
        for(i in 0 until n)sum[i+1]=sum[i]+a[i]
        for(i in 2..n){
            for(j in i-2 downTo 0){
                if(sum[i]-sum[j]<=mx)chk[sum[i]-sum[j]]=true
                else break
            }
        }
        var ans=0
        for(i in a)if(chk[i])ans++
        printLine("$ans")
    }
    output()
}