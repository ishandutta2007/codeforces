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
    val(a,b,k)=ris()
    val A=Array(a+b){if(it<b)1 else 0}
    val B=Array(a+b){if(it<b)1 else 0}
    if((k>=a+b-1&&k!=0)||((a==0||b==1)&&k!=0))pln("No")
    else{
        pln("Yes")
        pln(A.joinToString(""))
        if(k==0||b==1){
        }else if(k>a){
            B[a+b-k-1]=0
            B[a+b-1]=1
        }else{
            B[b-1]=0
            B[b-1+k]=1
        }
        pln(B.joinToString(""))
    }
    output()
}