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
    var n=readInt()
    var M=0;var C=0
    repeat(n){
        var (m,c)=readInts()
        if(m>c)M++
        else if(c>m)C++
    }
    if(M>C)printLine("Mishka")
    else if(C>M)printLine("Chris")
    else printLine("Friendship is magic!^^")
    output()
}