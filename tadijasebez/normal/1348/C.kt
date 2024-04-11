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
    var t=readInt()
    for(tc in 1..t){
        var (n, k)=readInts()
        var s=readLn()
        var cnt=Array(26){0}
        for(i in 0 until n)cnt[s[i]-'a']++
        var idx=-1
        var las=-1
        var dst=0
        for(i in 25 downTo 0){
            if(cnt[i]>0){
                idx=i
                dst++
            }
        }
        for(i in 0 until 26){
            if(cnt[i]>0)las=i
        }
        var ans=ArrayList<Char>()
        if(cnt[idx]==n){
            var sz=(n + k - 1)/k
            for(i in 1..sz)ans.add('a'+idx)
        }else if(cnt[idx]<k){
            var ost=k-1
            for(i in 0 until 26){
                while(cnt[i] > 0){
                    if(ost==0)ans.add('a'+i)
                    ost--
                    cnt[i]--
                }
            }
        }else if(cnt[idx]==k && dst==2){
            var sz=(n-k+k-1)/k
            ans.add('a'+idx)
            for(i in 1..sz)ans.add('a'+las)
        }else{
            var ost=k-1
            for(i in 0 until 26){
                while(cnt[i]>0){
                    if(ost==0)ans.add('a'+i)
                    else ost--
                    cnt[i]--
                }
            }
        }
        printLine(ans.joinToString(""))
    }
    output()
}