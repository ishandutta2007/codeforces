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

val mod=998244353
fun main(){
    var (n,k)=readInts()
    var F=Array(n+1){1L}
    for(i in 1..n)F[i]=F[i-1]*i%mod
    var I=Array(n+1){1L}
    for(i in 2..n)I[i]=(mod-mod/i)*I[mod%i]%mod
    for(i in 1..n)I[i]=I[i-1]*I[i]%mod
    fun binom(n:Int,k:Int):Long=F[n]*I[k]%mod*I[n-k]%mod
    var ans=0L
    for(i in 1..n){
        var mx=n/i
        if(mx>=k){
            ans=(ans+binom(mx-1,k-1))%mod
        }
    }
    printLine("$ans")
    output()
}