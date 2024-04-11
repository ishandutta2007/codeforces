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
    val (n,m)=ris()
    var cnt=Array(n){Array(n){0} }
    var c1=Array(n){0}
    var c2=Array(n){0}
    var A=Array(m){0}
    var B=Array(m){0}
    for(i in 0 until m){
        val (a,b)=ris()
        A[i]=a-1
        B[i]=b-1
        cnt[A[i]][B[i]]++
        c1[A[i]]++
        c2[B[i]]++
    }
    var ans=1
    for(i in 0 until n){
        for(j in 0 until n)if(i!=j){
            var C1=cnt[i][j]
            var C2=c1[i]+c2[j]-C1*2
            var C3=m-C1-C2
            var my=(if(A[0]==i)1 else 0) + (if(B[0]==j)1 else 0)
            var rank=1
            if(my==0)rank=C1+C2+1
            else if(my==1)rank=C1+1
            ans=max(ans,rank)
        }
    }
    pln(ans)
    output()
}