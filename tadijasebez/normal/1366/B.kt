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
        var (n,x,m)=readInts()
        var l=x;var r=x
        repeat(m){
            var (a,b)=readInts()
            if(max(a,l)<=min(b,r)){
                l=min(l,a)
                r=max(r,b)
            }
        }
        printLine("${r-l+1}")
    }
    output()
}