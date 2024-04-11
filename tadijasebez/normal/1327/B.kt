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
        var n=readInt()
        var tk=Array(n+1){false}
        var A=0
        for(i in 1..n){
            var E=readInts().toIntArray()
            var ok=false
            for(i in 1..E[0]){
                if(!tk[E[i]]){
                    tk[E[i]]=true
                    ok=true
                    break
                }
            }
            if(!ok)A=i
        }
        if(A!=0){
            printLine("IMPROVE")
            for(i in 1..n)if(!tk[i]){
                printLine("$A $i")
                break
            }
        }else printLine("OPTIMAL")
    }
    output()
}