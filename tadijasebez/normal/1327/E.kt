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

val mod=998244353L
fun mul(x:Long,y:Long):Long=x*y%mod
fun add(x:Long,y:Long):Long=(x+y)%mod
fun sub(x:Long,y:Long):Long=(x-y+mod)%mod

fun main(){
    var n=readInt()
    var pow_10=Array(n+2){1L}
    for(i in 1..n+1)pow_10[i]=mul(pow_10[i-1],10L)
    var ans=Array(n+1){mul(pow_10[n-it+1],(n-it+1).toLong())}
    var sum=0L;var now=0L
    for(i in n downTo 1){
        ans[i]=sub(ans[i],now)
        sum=add(sum,ans[i])
        now=add(now,add(sum,ans[i]))
    }
    printLine(ans.sliceArray(1..n).joinToString(" "))
    output()
}