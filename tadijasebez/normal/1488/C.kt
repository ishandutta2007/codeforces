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
    val t=ri()
    for(tc in 1..t){
        var(n,x,y)=ris()
        if(x>y)x=y.also{y=x}
        var dif=y-x-1
        var A=x-1
        var B=n-y
        //var ans=max((2*A+2*B+dif+1)/2,max(2*A,2*B))
        var ans=2*n
        for(b in 0..dif){
            var a=dif-b
            var now=max(min(A+a*2,A*2+a),min(B+b*2,B*2+b))
            ans=min(ans,now)
        }
        pln(ans)
    }
    output()
}