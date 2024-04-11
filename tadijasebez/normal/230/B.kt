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

fun isPrime(x:Int):Boolean{
    if(x==1)return false
    for(i in 2 until x){
        if(i*i>x)break
        if(x%i==0)return false
    }
    return true
}

fun main(){
    var n=readInt()
    var a=readLongs()
    for(i in a){
        var s=sqrt(i.toDouble()).roundToInt()
        if(s.toLong()*s==i&&isPrime(s))printLine("YES")
        else printLine("NO")
    }
    output()
}