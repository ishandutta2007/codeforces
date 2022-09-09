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
        var (n,k1,k2)=readInts()
        k2=min(k2,k1*2)
        var str=readLn()
        var len=0;var ans=0
        for(c in str){
            if(c=='0'){
                ans+=(len/2)*k2+(len%2)*k1
                len=0
            }else len++
        }
        ans+=(len/2)*k2+(len%2)*k1
        printLine("$ans")
    }
    output()
}