import java.util.*
import kotlin.collections.ArrayList
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
    val (n,m)=ris()
    val dp=Array(n+1){Array(m+1){false}}
    dp[0][0]=true
    val K=Array(n+1){0}
    val T=Array(n+1){0}
    var pref=1
    var sum=0
    var ans=Array(n+1){0}
    for(i in 1..n){
        val (k,t)=ris()
        K[i]=k
        T[i]=t
        if(t==1){
            ans[i]=pref
            pref+=k
            for(j in 0..m)dp[i][j]=dp[i-1][j]
        }else{
            sum+=k
            for(j in m downTo 0){
                dp[i][j]=dp[i-1][j]
                if(j>=k){
                    dp[i][j]=dp[i][j] or dp[i-1][j-k]
                }
            }
        }
    }
    if(sum+pref-1>m){
        pln(-1)
    }else{
        val goal=sum/2
        var best=0
        for(i in goal downTo 0){
            if(dp[n][i]){
                best=i
                break
            }
        }
        fun Calc(a:Int,b:Int):Int{
            if(a==b)return a+b
            else return max(a,b)*2-1
        }
        if(pref-1+Calc(sum-best,best)>m){
            pln(-1)
        }else{
            val use=ArrayList<Int>()
            val not=ArrayList<Int>()
            for(i in n downTo 1)if(T[i]==2){
                if(best>=K[i] && dp[i-1][best-K[i]]){
                    best-=K[i]
                    use.add(i)
                }else not.add(i)
            }
            var ptr=pref
            for(i in not){
                ans[i]=ptr
                ptr+=K[i]*2
            }
            ptr=pref+1
            for(i in use){
                ans[i]=ptr
                ptr+=K[i]*2
            }
            var ret=ArrayList<Int>()
            for(i in 1..n)ret.add(ans[i])
            pln(ret)
        }
    }
    output()
}