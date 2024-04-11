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
        val str=rs()
        var ok=false
        for(c in str){
            if(c != '=')
                ok=true
        }
        if(!ok){
            pln("=")
        }else{
            var h1=false
            var h2=false
            for(c in str){
                if(c == '<'){
                    h1=true
                }else if(c == '>'){
                    h2=true
                }
            }
            if(h1 && h2)pln("?")
            else if(h1)pln("<")
            else pln(">")
        }
    }
    output()
}