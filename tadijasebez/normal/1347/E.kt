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
        val n=readInt()
        if(n<=3)printLine("-1")
        else{
            val a=Array(2){ArrayList<Int>()}
            for(i in 1..n)a[(n-i)%2].add(i)
            a[1].reverse()
            a[1][0]=a[1][1].also{a[1][1]=a[1][0]}
            printLine(a[0].joinToString(" ")+" "+a[1].joinToString(" "))
        }
    }
    output()
}