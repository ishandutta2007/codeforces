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

val N=15
val M=1 shl N
val inf=1e9.toInt()
val infll=1e18.toLong()

var dist=Array(N){Array(N){inf}}
fun FloydWarshall(n:Int){
    for(i in 0 until n)
        for(j in 0 until n)
            for(k in 0 until n)
                dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k])
    //for(i in 0 until n)for(j in 0 until n)printLine("${dist[i][j]}")
}

var dp=Array(M){Array(N){Array(N){inf}}}
var dp1=Array(M){Array(N){inf}}
var dp2=Array(N){ArrayList<Int>()}
var sub_sum=Array(M){0L}
var a=IntArray(0)
var full=Array(N){Array(N){infll}}
var srt=ArrayList<Pair<Long,Int>>()
fun SubDP(n:Int){
    for(mask in 0 until (1 shl n))for(i in 0 until n)if((mask shr i) and 1>0)sub_sum[mask]+=a[i].toLong()
    for(i in 0 until n)dp[1 shl i][i][i]=0
    for(mask in 0 until (1 shl n)){
        for(st in 0 until n)if((mask shr st) and 1>0){
            for(ed in 0 until n)if((mask shr ed) and 1>0 && st!=ed){
                for(i in 0 until n)if((mask shr i)and 1>0 && ed!=i){
                    dp[mask][st][ed]=min(dp[mask][st][ed],dp[mask-(1 shl ed)][st][i]+dist[i][ed])
                }
                if(mask==(1 shl n)-1){
                    full[st][ed]=dp[mask][st][ed].toLong()
                    full[st][st]=min(full[st][st],dp[mask][st][ed]+dist[ed][st].toLong())
                }
                dp1[mask][st]=min(dp1[mask][st],dp[mask][st][ed])
                //printLine("$mask $st $ed ${dp[mask][st][ed]}")
            }
            dp1[mask][st]=min(dp1[mask][st],dp[mask][st][st])
        }
    }
    for(mask in 0 until (1 shl n))srt.add(Pair(sub_sum[mask],mask))
    srt.sortWith(compareBy({it.first}))
    for(i in 0 until n){
        for(p in srt){
            dp2[i].add(dp1[p.second][i])
        }
        for(j in dp2[i].size-2 downTo 0)dp2[i][j]=min(dp2[i][j],dp2[i][j+1])
    }
}
fun Get(i:Int,C:Long,n:Int):Int{
    var bot=0;var top=srt.size;var idx=srt.size
    while(top>=bot){
        var mid=(top+bot)/2
        if(srt[mid].first>=C){idx=mid;top=mid-1}
        else bot=mid+1
    }
    return dp2[i][idx]
    //var ans=inf
    //for(mask in 0 until (1 shl n)){
    //    if(sub_sum[mask]>=C)ans=min(ans,dp1[mask][i])
    //}
    //return ans
}

fun mul(x:Array<Array<Long>>,y:Array<Array<Long>>,n:Int):Array<Array<Long>>{
    var ans=Array(n){Array(n){infll}}
    for(i in 0 until n){
        for(j in 0 until n){
            for(k in 0 until n){
                ans[i][j]=min(ans[i][j],x[i][k]+y[k][j])
            }
        }
    }
    return ans
}
fun mul(x:Array<Array<Long>>,y:Array<Long>,n:Int):Array<Long>{
    var ans=Array(n){infll}
    for(i in 0 until n){
        for(k in 0 until n){
            ans[i]=min(ans[i],x[k][i]+y[k])
        }
    }
    return ans
}

var fir=true
val LG=60
var pws=Array(0){Array(0){Array(0){0L}}}
fun pow(n:Int,_k:Long,s:Int):Array<Long>{
    var ans=Array(n){if(it==s)0L else infll}
    var k=_k;var ptr=0
    while(k>0){
        if(k and 1>0)ans=mul(pws[ptr],ans,n)
        k/=2;ptr++
    }
    return ans
}
fun MatrixDP(n:Int,k:Long,s:Int):Array<Long>{
    if(fir){
        pws=Array(LG){Array(n){Array(n){infll}}}
        for(i in 0 until n)pws[0]=full
        for(i in 1 until LG)pws[i]=mul(pws[i-1],pws[i-1],n)
        fir=false
    }
    var pw=pow(n,k,s)
    return pw
}

fun main(){
    var (n,m,q,s)=readInts();s--
    a=readInts().toIntArray()
    var sum=0L;for(i in a)sum+=i.toLong()
    for(i in 1..m){
        var (u,v)=readInts()
        dist[u-1][v-1]=1
    }
    FloydWarshall(n)
    SubDP(n)
    var o=ArrayList<Long>()
    var Qs=readLongs()
    for(C in Qs){
        var fsz=C/sum
        var mat=MatrixDP(n,fsz,s)
        var ans=infll
        for(i in 0 until n){
            ans=min(ans,Get(i,C-fsz*sum,n)+mat[i])
            //printLine("$i ${Get(i,C-fsz*sum,n)} ${mat[i]}")
        }
        printLine("$ans")
    }
    output()
}