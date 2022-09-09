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
    val t=ri()
    for(tc in 1..t){
        val n=ri()
        var a=ris()
        var b=ris()
        val ord_a=Array(n){it}
        val ord_b=Array(n){it}
        ord_a.sortBy({i:Int->a[i]})
        ord_b.sortBy({i:Int->b[i]})
        a=a.sorted()
        b=b.sorted()
        var ans=0;var best=0
        for(x in 0..n){
            var now=inf
            for(i in 0 until x){
                now=min(now,abs(a[i]-b[n-x+i]))
            }
            for(i in x until n){
                now=min(now,abs(a[i]-b[i-x]))
            }
            ans=max(ans,now)
            if(ans==now){
                best=x
            }
        }
        var pos=Array(n){0}
        for(i in 0 until best){
            pos[ord_a[i]]=ord_b[n-best+i]+1
        }
        for(i in best until n){
            pos[ord_a[i]]=ord_b[i-best]+1
        }
        pln(pos)
    }
    output()
}