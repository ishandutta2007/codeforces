import java.util.*
import java.math.*
 
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
        var (x,n,m)=readInts()
        for(i in 1..n)
            x=Math.min(x,x/2+10)
        x-=m*10;
        if(x<=0)printLine("YES")
        else printLine("NO")
    }
    output()
}