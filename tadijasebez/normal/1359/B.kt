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
        var (n,m,x,y)=readInts()
        y=min(y,x*2)
        var ans=0
        for(i in 0 until n){
            var str=readLn();var len=0
            for(c in str){
                if(c=='.')len++
                else{
                    ans+=(len/2)*y+(len%2)*x
                    len=0;
                }
            }
            ans+=(len/2)*y+(len%2)*x
        }
        printLine("$ans")
    }
    output()
}