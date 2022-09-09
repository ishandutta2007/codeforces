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
    val n=ri()
    val a=ris()
    val b=ArrayList<Int>()
    val pos=ArrayList<Int>()
    val neg=ArrayList<Int>()
    var all=0L
    for(i in 0 until n){
        if(a[i]>0){pos.add(i);b.add(1)}
        else{neg.add(i);b.add(-1)}
        all+=abs(a[i])
    }
    pos.sortBy{i:Int->a[i]}
    neg.sortBy{i:Int->-a[i]}
    fun Check():Boolean{
        var sum=0;var ok=false
        for(i in 0 until n){
            if(b[i]>0)sum++
            else sum+=2
            if(i>0&&b[i]==b[i-1])ok=true
        }
        return sum%3==1&&(ok||n==1)
    }
    var ans=-all
    fun Consider(o:List<Int>){
        var now=all
        for(i in o){
            b[i]*=-1
            now-=2*abs(a[i])
        }
        if(Check())ans=max(ans,now)
        for(i in o)b[i]*=-1
    }
    val cand=ArrayList<Int>()
    for(i in 0 until min(3,pos.size))cand.add(pos[i])
    for(i in 0 until min(3,neg.size))cand.add(neg[i])
    for(mask in 0 until (1 shl cand.size)){
        val tmp=ArrayList<Int>()
        for(i in 0 until cand.size){
            if((mask shr i) and 1 == 1)tmp.add(cand[i])
        }
        Consider(tmp)
    }
    pln(ans)
    output()
}