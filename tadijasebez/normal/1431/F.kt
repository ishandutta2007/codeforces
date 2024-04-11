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
    val(n,k,x)=ris()
    val a=ris()
    var top=x.toLong()*100000;var bot=0L;var ans=0L
    while(top>=bot){
        val mid=(top+bot)/2
        var ptr=0;var ost=k
        var ok=true
        while(ptr<n){
            var pq=PriorityQueue<Int>()
            var sum=0L
            for(i in 0 until x){
                if(ptr<n){
                    sum+=a[ptr]
                    pq.add(-a[ptr])
                    ptr++
                }
            }
            while(sum>mid){
                if(ost==0){ok=false;break}
                ost--
                sum+=pq.poll()
                if(ptr<n){
                    pq.add(-a[ptr])
                    sum+=a[ptr]
                    ptr++
                }
            }
            if(!ok)break
        }
        if(ok){ans=mid;top=mid-1}
        else bot=mid+1
    }
    pln(ans)
    output()
}