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
        var pw=1;var ans=ArrayList<Int>()
        while(n>0){
            if(n%10!=0)ans.add((n%10)*pw)
            n/=10;pw*=10
        }
        printLine("${ans.size}")
        printLine(ans.joinToString(" "))
    }
    output()
}