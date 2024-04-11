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
    var n=readInt();n--
    var names=arrayOf("Sheldon","Leonard","Penny","Rajesh","Howard")
    var sz=1
    while(sz*5<=n){
        n-=sz*5
        sz*=2
    }
    printLine(names[n/sz])
    output()
}