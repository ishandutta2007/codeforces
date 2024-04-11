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
        var (n,m,a,b)=readInts()
        var ans=Array(n){Array(m){0}}
        var ptr=0;var cnt=0
        for(j in 0 until m){
            repeat(b){
                ans[ptr][j]=1
                ptr++
                if(ptr==n){ptr=0;cnt++}
            }
        }
        if(ptr==0&&cnt==a){
            printLine("YES")
            for(i in 0 until n)printLine(ans[i].joinToString(""))
        }else printLine("NO")
    }
    output()
}