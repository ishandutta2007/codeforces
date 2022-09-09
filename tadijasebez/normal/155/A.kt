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
    var a=readInts().toIntArray()
    var mn=a[0];var mx=a[0];var ans=0
    for(i in a){
        if(mx<i){
            ans++
            mx=i
        }
        if(mn>i){
            ans++
            mn=i
        }
    }
    printLine("$ans")
    output()
}