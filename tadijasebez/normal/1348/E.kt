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

val inf=(-1e18).toLong()

fun main(){
    val (n,k)=readInts()
    val dp=Array(n+1){Array(k){false}}
    var sum=0L
    dp[0][0]=true
    for(i in 1..n){
        val (a,b)=readInts()
        for(j in 0 until k){
            if(!dp[i-1][j])continue
            var bl=(a+b)%k
            for(rd in 0 until k){
                if(rd<=a && bl<=b){
                    var jj=rd+j
                    if(jj>=k)jj-=k
                    dp[i][jj]=true
                }
                bl--
                if(bl<0)bl+=k
            }
        }
        sum+=a+b
    }
    var ans=0L
    for(i in 0 until k)if(dp[n][i])ans=max(ans,(sum-i)/k)
    printLine("$ans")
    output()
}