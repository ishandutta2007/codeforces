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
    var (n,m)=readInts()
    var ids=Array(2){ArrayList<Pair<Int,Int>>()}
    for(i in 1..n){
        var (a,b)=readInts()
        ids[a-1].add(Pair(b,i))
    }
    ids[0]=ArrayList(ids[0].sortedBy({-it.first}))
    ids[1]=ArrayList(ids[1].sortedBy({-it.first}))
    var sum=Array(2){Array(ids[it].size+1){0}}
    for(i in 0..1)for(j in 1..ids[i].size)sum[i][j]=sum[i][j-1]+ids[i][j-1].first
    var L=0;var R=0;var ans=0
    for(i in 0..ids[1].size){
        if(i*2>m)break
        var now=sum[1][i]+sum[0][min(ids[0].size,m-2*i)]
        if(now>ans){ans=now;L=i;R=min(ids[0].size,m-2*i)}
    }
    printLine("$ans")
    var lne=ArrayList<Int>()
    for(i in 0 until R)lne.add(ids[0][i].second)
    for(i in 0 until L)lne.add(ids[1][i].second)
    printLine(lne.joinToString(" "))
    output()
}