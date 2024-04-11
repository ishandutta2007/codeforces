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

val inf=(1e9+7).toInt()

fun main(){
    var t=readInt()
    for(tc in 1..t){
        var (n,m,a,b,c)=readInts()
        var p=readLongs().toLongArray()
        p.sort()
        var sum=LongArray(m+1){0}
        for(i in 1..m)sum[i]=sum[i-1]+p[i-1]
        var E=Array(n+1){ArrayList<Int>()}
        for(i in 1..m){
            var (u,v)=readInts()
            E[u].add(v)
            E[v].add(u)
        }
        fun BFS(s:Int,n:Int,dist:IntArray){
            val q=LinkedList<Int>()
            for(i in 1..n)dist[i]=inf
            q.add(s)
            dist[s]=0
            while(!q.isEmpty()){
                var u=q.remove()
                for(v in E[u])
                    if(dist[v]>dist[u]+1){
                        dist[v]=dist[u]+1
                        q.add(v)
                    }
            }
        }
        var A=IntArray(n+1){inf}
        var B=IntArray(n+1){inf}
        var C=IntArray(n+1){inf}
        BFS(a,n,A)
        BFS(b,n,B)
        BFS(c,n,C)
        var ans=1e18.toLong()
        for(i in 1..n){
            if(A[i]+B[i]+C[i]>m)continue
            var now=sum[A[i]+B[i]+C[i]]+sum[B[i]]
            ans=min(ans,now)
        }
        printLine("$ans")
    }
    output()
}