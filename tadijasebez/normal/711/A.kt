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
    var ans=ArrayList<String>()
    var ok=false
    repeat(n){
        var tmp=readLn()
        if(ok)ans.add(tmp)
        else{
            if(tmp.substring(0..1)=="OO"){
                tmp="++"+tmp.substring(2..4)
                ok=true
            }else if(tmp.substring(3..4)=="OO") {
                tmp=tmp.substring(0..2)+"++"
                ok=true
            }
            ans.add(tmp)
        }
    }
    if(ok){
        printLine("YES")
        printLine(ans.joinToString("\n"))
    }else printLine("NO")
    output()
}