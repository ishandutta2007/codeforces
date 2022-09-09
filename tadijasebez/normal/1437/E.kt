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

fun<T:Comparable<T>> ArrayList<T>.lower_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<x)bot=mid+1
        else top=mid
    }
    return bot
}
fun<T:Comparable<T>> ArrayList<T>.upper_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<=x)bot=mid+1
        else top=mid
    }
    return bot
}
fun<T:Comparable<T>> Array<T>.lower_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<x)bot=mid+1
        else top=mid
    }
    return bot
}
fun<T:Comparable<T>> Array<T>.upper_bound(x:T):Int{
    var top=this.size;var bot=0
    while(top>bot){
        val mid=(top+bot) shr 1
        if(this[mid]<=x)bot=mid+1
        else top=mid
    }
    return bot
}

fun main(){
    val(n,k)=ris()
    val a=ris().toIntArray()
    val mark=Array(n){false}
    if(k>0){
        for(i in ris()){
            mark[i-1]=true
        }
    }
    var lis=ArrayList<Int>()
    var las=-n;var ans=0;var ok=true
    for(i in 0 until n){
        a[i]-=i
        if(mark[i]){
            if(las>a[i]){
                ok=false
            }
            while(lis.size>0){
                if(lis.last()<=a[i])ans++
                lis.removeAt(lis.size-1)
            }
            lis=ArrayList()
            las=a[i]
            ans++
        }else if(a[i]>=las){
            val j=lis.upper_bound(a[i])
            if(j==lis.size)lis.add(a[i])
            else lis[j]=a[i]
        }
    }
    ans+=lis.size
    if(ok)pln(n-ans)
    else pln(-1)
    output()
}