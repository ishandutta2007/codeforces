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
        var mx=Array(n+1){0}
        var U=Array(m+1){0}
        var V=Array(m+1){0}
        var W=Array(m+1){0}
        for(i in 1..m){
            var (u,v,w)=readInts()
            mx[u]=max(mx[u],w)
            mx[v]=max(mx[v],w)
            U[i]=u;V[i]=v;W[i]=w
        }
        var ok=true
        for(i in 1..m){
            if(W[i]!=min(mx[V[i]],mx[U[i]]))ok=false
        }
        if(ok){
            printLine("YES")
            var o=ArrayList<Int>()
            for(i in 1..n)o.add(mx[i])
            printLine(o.joinToString(" "))
        }else printLine("NO")
    }
    output()
}