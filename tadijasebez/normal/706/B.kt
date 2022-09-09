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

fun IntArray.upper_bound(x:Int):Int{
    var top=size;var bot=0
    while(top>bot){
        var mid=(top+bot) shr 1
        if(this[mid]<=x)bot=mid+1
        else top=mid
    }
    return bot
}

fun main(){
    var n=readInt()
    var a=readInts().sorted().toIntArray()
    var q=readInt()
    while(q-->0){
        var x=readInt()
        var idx=a.upper_bound(x)
        printLine("$idx")
    }
    output()
}