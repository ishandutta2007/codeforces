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
    val t=readInt()
    repeat(t){
        var n=readInt()
        var c2=0;var c3=0
        while(n%2==0){
            n/=2
            c2++
        }
        while(n%3==0){
            n/=3
            c3++
        }
        if(n==1&&c3>=c2)printLine("${c3-c2+c3}")
        else printLine("-1")
    }
    output()
}