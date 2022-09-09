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

val inf=1e9.toInt()
fun main(){
    val(n,k)=ris()
    val a=ris().sorted()
    val sum=ArrayList<Int>()
    sum.add(0)
    for(i in a)sum.add(sum.last()+i)
    val dp=Array(n+1){Array(k+1){-inf}}
    dp[0][0]=0
    fun Get(i:Int,z:Int):Int{
        var ans=sum[i]-sum[i-z]
        ans-=sum[i-z]-sum[i-2*z]
        return ans
    }
    for(i in 1..n){
        for(j in 0..k){
            var z=1
            dp[i][j]=max(dp[i][j],dp[i-1][j])
            while(z*2<=i&&z<=j){
                dp[i][j]=max(dp[i][j],dp[i-2*z][j-z]+Get(i,z))
                z++
            }
        }
    }
    pln(dp[n][k])
    output()
}