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
    var (n,m,q)=readInts()
    var xs=Array(n+1){0L}
    var ys=Array(m+1){0L}
    var mat=Array(n+1){Array(m+1){0}}
    for(i in 1..n){
        var tmp=readInts().toIntArray()
        for(j in 0 until m){
            mat[i][j+1]=tmp[j]
            xs[i]+=tmp[j].toLong()
            ys[j+1]+=tmp[j].toLong()
        }
    }
    fun Get(xs:Array<Long>,n:Int):Long{
        var sum=0L;var cnt=0L
        for(i in 1..n){
            sum+=(i-1)*xs[i]
            cnt+=xs[i]
        }
        var now=sum;var pre=0L
        for(i in 1..n){
            now=min(now,sum)
            pre+=xs[i]
            cnt-=xs[i]
            sum-=cnt
            sum+=pre
        }
        return now
    }
    var ans=ArrayList<Long>()
    ans.add(Get(xs,n)+Get(ys,m))
    repeat(q){
        var (x,y,w)=readInts()
        xs[x]+=w-mat[x][y].toLong()
        ys[y]+=w-mat[x][y].toLong()
        mat[x][y]=w
        ans.add(Get(xs,n)+Get(ys,m))
    }
    printLine(ans.joinToString(" "))
    output()
}