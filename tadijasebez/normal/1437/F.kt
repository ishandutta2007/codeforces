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

val mod=998244353
class mod_int(x:Int){
    var n:Int=x
    operator fun plus(b:mod_int):mod_int{
        var ans=n+b.n
        if(ans>=mod)ans-=mod
        return mod_int(ans)
    }
    operator fun minus(b:mod_int):mod_int{
        var ans=n-b.n
        if(ans<0)ans+=mod
        return mod_int(ans)
    }
    operator fun times(b:mod_int)=mod_int((n.toLong()*b.n%mod).toInt())
    fun exp(_k:Long):mod_int{
        var k=_k;var ans=mod_int(1);var x=this
        while(k>0){
            if(k%2==1.toLong())ans*=x
            x*=x
            k/=2
        }
        return ans
    }
    fun inv()=this.exp(mod.toLong()-2)
    operator fun div(b:mod_int)=this*b.inv()
    override fun toString()=n.toString()
}

val N=5050
var F=Array(N){mod_int(0)}
var I=Array(N){mod_int(0)}
fun calc(){
    F[0]=mod_int(1);for(i in 1 until N)F[i]=F[i-1]*mod_int(i)
    I[N-1]=F[N-1].inv();for(i in N-2 downTo 0)I[i]=I[i+1]*mod_int(i+1)
}
fun binom(n:Int,k:Int):mod_int=F[n]*I[k]*I[n-k]

fun main(){
    calc()
    val n=ri()
    val a=ris().sorted()
    val dp=Array(n+1){mod_int(0)}
    val carry=Array(n+1){0}
    dp[0]=mod_int(1)
    for(i in 1..n){
        var take=0
        for(j in i-1 downTo 0){
            if(j==0||a[i-1]>=a[j-1]*2){
                dp[i]+=dp[j]*binom(n-j+carry[j]-1,carry[j]+take)*F[carry[j]+take]
                take++
            }else carry[i]++
        }
    }
    if(carry[n]==0)pln(dp[n].n)
    else pln(0)
    output()
}