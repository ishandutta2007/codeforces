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

val inf=1e9.toInt()
fun main(){
    var (n,m,k)=readInts()
    var dp=Array(n+1){inf}
    dp[k]=0
    for(i in 1..m){
        var (x,y)=readInts()
        var nx=min(dp[x]+1,dp[y])
        var ny=min(dp[y]+1,dp[x])
        dp[x]=nx
        dp[y]=ny
    }
    var o=ArrayList<Int>()
    for(i in 1..n){
        if(dp[i]==inf)o.add(-1)
        else o.add(dp[i])
    }
    printLine(o.joinToString(" "))
    output()
}