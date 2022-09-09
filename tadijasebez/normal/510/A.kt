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
    var (n,m)=readInts()
    for(i in 0 until n){
        if(i%2==0)printLine(Array(m){'#'}.joinToString(""))
        else if(i%4==1)printLine(Array(m){if(it==m-1)'#' else '.'}.joinToString(""))
        else printLine(Array(m){if(it==0)'#' else '.'}.joinToString(""))
    }
    output()
}