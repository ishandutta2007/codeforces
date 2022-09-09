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
    var n=readInt()
    var E=Array(n+1){ArrayList<Int>()}
    for(i in 1 until n){
        var (u,v)=readInts()
        E[u].add(v)
        E[v].add(u)
    }
    var mxd=0
    for(i in 1..n)mxd=max(mxd,E[i].size)
    var ans=ArrayList<Pair<Int,Int>>()
    fun DFS(u:Int,t:Int,p:Int){
        ans.add(Pair(u,t))
        var now=t
        var cnt=0
        for(v in E[u])if(v!=p)cnt++
        for(v in E[u])if(v!=p){
            if(now==mxd){
                now=t-1-cnt
                ans.add(Pair(u,now))
            }
            now++
            DFS(v,now,u)
            ans.add(Pair(u,now))
            cnt--
        }
        if(p!=0 && now!=t-1)ans.add(Pair(u,t-1))
    }
    DFS(1,0,0)
    printLine("${ans.size}")
    for(i in ans)printLine("${i.first} ${i.second}")
    output()
}