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

fun Ask(l:Int,r:Int):Int{
    println("? $l $r")
    return ri()
}

fun main(){
    val n=ri()
    val sec=Ask(1,n)
    var ans=-1
    if(sec!=1&&Ask(1,sec)==sec){
        var top=sec-1
        var bot=1
        while(top>=bot){
            val mid=(top+bot) shr 1
            if(Ask(mid,sec)==sec){ans=mid;bot=mid+1}
            else top=mid-1
        }
    }else{
        var top=n
        var bot=sec+1
        while(top>=bot){
            val mid=(top+bot) shr 1
            if(Ask(sec,mid)==sec){ans=mid;top=mid-1}
            else bot=mid+1
        }
    }
    println("! $ans")
    //output()
}