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
        var (n,m)=readInts()
        var cnt=Array(2){Array(n+m){0}}
        for(i in 0 until n){
            var tmp=readInts().toIntArray()
            for(j in 0 until m){
                cnt[tmp[j]][i+j]++
            }
        }
        var ans=0;var sz=n+m-1
        for(i in 0 until sz/2){
            //printLine("$i -")
            ans+=min(cnt[0][i]+cnt[0][n+m-2-i],cnt[1][i]+cnt[1][n+m-2-i])
        }
        printLine("$ans")
    }
    output()
}