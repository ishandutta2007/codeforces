import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    var a=readLn()
    var b=readLn()
    var ans=""
    for(i in a.indices){
        if(a[i]==b[i])ans+="0"
        else ans+="1"
    }
    printLine(ans)
    output()
}