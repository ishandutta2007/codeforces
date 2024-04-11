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
        var (n,k)=readInts()
        var m=n/k
        var str=readLn()
        var ans=0
        for(j in 0 until (k+1)/2){
            var cnt=Array(26){0}
            for(i in 0 until m){
                var a=i*k+j
                var b=i*k+k-j-1
                cnt[str[a]-'a']++
                if(a!=b)cnt[str[b]-'a']++
            }
            var mx=0;var sum=0
            for(i in 0 until 26){
                mx=max(mx,cnt[i])
                sum+=cnt[i]
            }
            ans+=sum-mx
        }
        printLine("$ans")
    }
    output()
}