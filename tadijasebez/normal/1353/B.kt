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
        var (n,k)=readInts()
        var a=readInts().sorted().toIntArray()
        var b=readInts().sortedDescending().toIntArray()
        for(i in 0 until min(n,k)){
            if(a[i]<b[i])a[i]=b[i].also{b[i]=a[i]}
        }
        printLine("${a.sum()}")
    }
    output()
}