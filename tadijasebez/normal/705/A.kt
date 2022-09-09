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
    if(n%2==1){
        var ans="I hate it"
        n--
        while(n>=2){
            n-=2
            ans="I hate that I love that "+ans
        }
        if(n==1)ans="I love that "+ans
        printLine(ans)
    }else{
        var ans="I love it"
        n--
        while(n>=2){
            n-=2
            ans="I love that I hate that "+ans
        }
        if(n==1)ans="I hate that "+ans
        printLine(ans)
    }
    output()
}