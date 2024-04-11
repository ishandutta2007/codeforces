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

class BinaryIndexedTree(val n:Int){
    val sum=Array(n){0L}
    fun Add(idx:Int,f:Long){
        var i=idx+1
        while(i<=n){
            sum[i-1]+=f
            i+=i and -i
        }
    }
    fun Get(idx:Int):Long{
        var i=idx+1;var ans=0L
        while(i>0){
            ans+=sum[i-1]
            i-=i and -i
        }
        return ans
    }
    fun Get(l:Int,r:Int):Long{
        return Get(r)-Get(l-1)
    }
}

fun main(){
    val n=ri()
    val s=rs()
    val ids=TreeMap<Char,ArrayList<Int>>()
    for(i in 0 until n){
        if(!ids.containsKey(s[i]))ids[s[i]]=ArrayList<Int>()
        ids[s[i]]!!.add(i)
    }
    data class Range(val l:Int,val r:Int)
    val intervals=ArrayList<Range>()
    for(c in 'a'..'z'){
        if(ids.containsKey(c)){
            val m=ids[c]!!.size
            for(i in 0 until m){
                intervals.add(Range(ids[c]!![i],n-ids[c]!![m-i-1]-1))
            }
        }
    }
    intervals.sortWith(compareBy({it.l},{it.r}))
    val BIT=BinaryIndexedTree(n)
    var ans=0L
    for(interval in intervals){
        var(l,r)=interval
        ans+=BIT.Get(r,n-1)
        BIT.Add(r,1)
    }
    pln(ans)
    output()
}