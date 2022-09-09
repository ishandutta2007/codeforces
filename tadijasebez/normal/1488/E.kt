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
        var n=ri()
        val a=ris()
        val ids=Array(n+1){ArrayList<Int>()}
        val b=ArrayList<Int>()
        for(i in 0 until n){
            ids[a[i]].add(i)
        }
        for(i in 0 until n){
            if(ids[a[i]].size==2&&ids[a[i]][0]==i){
                b.add(ids[a[i]][1])
            }
        }
        val lds=ArrayList<Int>()
        val cand=ArrayList<Int>()
        for(i in b){
            var top=lds.size
            var bot=0
            while(top>bot){
                var mid=(bot+top) shr 1
                if(lds[mid]>=i)bot=mid+1
                else top=mid
            }
            if(bot==lds.size){
                cand.clear()
                lds.add(i)
                cand.add(i)
            }else{
                if(bot+1==lds.size)cand.add(i)
                lds[bot]=i
            }
        }
        var ans=2*lds.size
        var odd=false
        for(c in cand){
            if(ids[a[c]][1]-ids[a[c]][0]>1)odd=true
        }
        if(odd)ans++
        pln(max(1,ans))
    }
    output()
}