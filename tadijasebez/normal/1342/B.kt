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
        var str=readLn()
        var ok=true
        for(i in 1 until str.length){
            if(str[i]!=str[0])
                ok=false
        }
        if(ok)printLine(str)
        else{
            var ans=ArrayList<Char>()
            for(i in 0 until str.length){
                ans.add('0')
                ans.add('1')
            }
            printLine(ans.joinToString(""))
        }
    }
    output()
}