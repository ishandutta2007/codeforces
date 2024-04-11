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
    var t=readInt()
    for(tc in 1..t){
        var (n,k)=readInts()
        var a=readInts().toIntArray()
        var b=mutableSetOf<Int>()
        for(i in a)b.add(i)
        if(b.size>k){
            printLine("-1")
        }else{
            for(i in 1..n){
                if(!b.contains(i) && b.size<k)
                    b.add(i)
            }
            printLine("${n*k}")
            var ans = Array(n*k){0}
            for (i in 0 until n*k)
                ans[i]=b.elementAt(i%k)
            printLine(ans.joinToString(" "))
        }
    }
    output()
}