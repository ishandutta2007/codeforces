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

var correct=Array(16){false}

fun main(){
    for(mask in 0 until 16){
        var bal=0
        var ok=true
        for(i in 0 until 4){
            if(((mask shr i) and 1) == 1){
                bal--
            }else bal++
            if(bal<0)ok=false
        }
        if(bal!=0)ok=false
        correct[mask]=ok
    }
    val t=ri()
    for(tc in 1..t){
        val n=ri()
        val s=rs()
        val reg=rs()
        val inf=1000000000
        var dp=Array(n+1){Array(16){inf} }
        for(mask in 0 until 16){
            var cnt=0
            for(i in 0 until 4){
                var now='('
                if(((mask shr i) and 1) == 1){
                    now=')'
                }
                if(now!=s[i]){
                    cnt++
                }
            }
            if(reg[0]=='1'){
                if(correct[mask]){
                    dp[4][mask]=cnt
                }
            }else{
                dp[4][mask]=cnt
            }
        }
        for(i in 5..n){
            for(mask in 0 until 16){
                for(last in 0..1){
                    var nmsk=(mask shr 1) + last * 8
                    var nch=if(last==1)')' else '('
                    var add=0
                    if(s[i-1]!=nch)add=1
                    if(reg[i-4]=='1'){
                        if(correct[nmsk]){
                            dp[i][nmsk]=min(dp[i][nmsk],dp[i-1][mask]+add)
                        }
                    }else{
                        dp[i][nmsk]=min(dp[i][nmsk],dp[i-1][mask]+add)
                    }
                }
            }
        }
        var ans=inf
        for(mask in 0 until 16){
            ans=min(ans,dp[n][mask])
        }
        if(ans==inf)pln(-1)
        else pln(ans)
    }
    output()
}