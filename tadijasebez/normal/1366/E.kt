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
val mod=998244353
fun add(x:Int,y:Int):Int=if(x+y>=mod)x+y-mod else x+y
fun sub(x:Int,y:Int):Int=if(x-y<0)x-y+mod else x-y
fun mul(x:Int,y:Int):Int=(x.toLong()*y%mod).toInt()
fun powmod(_x:Int,_k:Int):Int{
    var ans=1;var x=_x;var k=_k
    while(k>0){
        if(k and 1>0)ans=mul(ans,x)
        k=k/2;x=mul(x,x)
    }
    return ans
}

fun main(){
    var (n,m)=readInts()
    var a=readInts().toIntArray()
    var b=readInts().toIntArray()
    var idx=Array(n){it}
    idx.sortWith(compareBy{a[it]})
    var ans=1;var ptr=0;var las=-1;var ok=true
    for(i in 0 until m){
        var nxt=if(i+1==m)inf else b[i+1]
        if(ptr<n&&a[idx[ptr]]<b[i]){ok=false;break}
        if(ptr==n||a[idx[ptr]]!=b[i]){ok=false;break}
        var exp=0;var lo=0
        while(ptr<n&&a[idx[ptr]]<nxt){
            if(a[idx[ptr]]==b[i])lo=max(lo,idx[ptr])
            exp=max(exp,idx[ptr])
            ptr++
        }
        if(exp<=las){ok=false;break}
        if(i!=0)ans=mul(ans,lo-las)
        //printLine("$exp $lo $las")
        las=exp
    }
    if(ok)printLine("$ans")
    else printLine("0")
    output()
}