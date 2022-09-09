import java.util.*
import kotlin.math.*

fun rs()=readLine()!!
fun ri()=rs().toInt()
fun rl()=rs().toLong()
fun rd()=rs().toDouble()
fun ris()=rs().split(" ").map{it.toInt()}
fun rls()=rs().split(" ").map{it.toLong()}
fun rds()=rs().split(" ").map{it.toDouble()}

val out=mutableListOf<String>()
fun pln(s:String){out.add(s)}
fun pln(i:Int)=pln(i.toString())
fun pln(l:Long)=pln(l.toString())
fun pln(d:Double,precision:Int=12)=pln(("%."+precision.toString()+"f").format(d))
fun pln(a:IntArray)=pln(a.joinToString(" "))
fun pln(a:LongArray)=pln(a.joinToString(" "))
fun<T> pln(a:Array<T>)=pln(a.joinToString(" "))
fun<T> pln(a:ArrayList<T>)=pln(a.joinToString(" "))
fun output(){println(out.joinToString("\n"))}

fun main(){
    val s=rs()
    val n=s.length
    var cnt=Array(2){Array(n+1){0}}
    var ids=Array(2){ArrayList<Int>()}
    for(i in 1..n){
        cnt[0][i]=cnt[0][i-1]
        cnt[1][i]=cnt[1][i-1]
        if(s[i-1]=='0')cnt[0][i]++
        else cnt[1][i]++
        if(s[i-1]=='0'){
            ids[0].add(i)
        }else{
            ids[1].add(i)
        }
    }
    fun get(c:Int,i:Int,k:Int):Int{
        val pre=cnt[c][i-1]
        if(ids[c].size<=pre+k)return n
        return ids[c][pre+k]-1
    }
    var sol=ArrayList<Int>()
    for(k in 1..n){
        var ptr=1
        var ans=0
        while(ptr<=n){
            var mx=max(get(0,ptr,k),get(1,ptr,k))
            ptr=mx+1
            ans++
        }
        sol.add(ans)
    }
    pln(sol)
    output()
}