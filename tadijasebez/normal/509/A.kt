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
    var a=Array(n){Array(n){1L}}
    for(i in 1 until n){
        for(j in 1 until n){
            a[i][j]=a[i-1][j]+a[i][j-1]
        }
    }
    printLine("${a[n-1][n-1]}")
    output()
}