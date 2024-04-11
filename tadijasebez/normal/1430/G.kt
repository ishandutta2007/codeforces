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
    val(n,m)=ris()
    val E=Array(n){0};val S=Array(1 shl n){0}
    data class Edge(val v:Int,val w:Int)
    val G=Array(n){ArrayList<Edge>()}
    for(i in 0 until m){
        val(u,v,w)=ris()
        E[u-1]=E[u-1] or (1 shl (v-1))
        G[v-1].add(Edge(u-1,w))
    }
    for(i in 0 until n)S[1 shl i]=E[i]
    for(i in 1 until (1 shl n)){
        val bit=i and (-i)
        S[i]=S[i-bit] or S[bit]
    }
    val a=Array(n){0}
    val dp=Array(1 shl n){-1}
    val best=Array(1 shl n){-1}
    val inf=1e9.toInt()
    for(mask in 1 until (1 shl n)){
        var sub=mask;var ans=inf;var sum=0
        for(i in 0 until n)if((mask shr i) and 1 == 1)for(e in G[i])if((mask shr e.v) and 1 == 0)sum+=e.w
        while(sub!=0){
            val out=S[sub]
            val other=mask xor sub
            if(out and (other xor ((1 shl n)-1)) == 0){
                val now=dp[other]
                if(ans>now){ans=now;best[mask]=other}
            }
            sub=(sub-1) and mask
        }
        dp[mask]=ans+sum
    }
    var mask=(1 shl n)-1
    var dep=n
    while(mask!=0){
        val sub=mask xor best[mask]
        for(i in 0 until n)if((sub shr i) and 1 == 1)a[i]=dep
        mask=best[mask];dep--
    }
    pln(a)
    output()
}