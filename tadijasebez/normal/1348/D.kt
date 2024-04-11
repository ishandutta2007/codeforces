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
        var n=readInt()
        n--
        var ans=ArrayList<Int>()
        var cnt=1
        while(n>0){
            if(n<4*cnt)break
            ans.add(cnt)
            n-=cnt*2
            cnt*=2
        }
        if(n<=cnt*2)ans.add(n-cnt)
        else{
            var m=n-2*cnt
            var a=m/2
            var b=m-a*2
            ans.add(a)
            ans.add(b)
        }
        printLine("${ans.size}")
        printLine(ans.joinToString(" "))
    }
    output()
}