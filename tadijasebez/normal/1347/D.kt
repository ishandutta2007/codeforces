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
        var a=LinkedList(readInts())
        var now=0;var A=0;var B=0;var pl=0;var cnt=0
        while(!a.isEmpty()){
            cnt++
            if(pl==0){
                var tmp=0
                while(!a.isEmpty() && tmp<=now){A+=a.first();tmp+=a.first();a.pollFirst()}
                now=tmp
            }else{
                var tmp=0
                while(!a.isEmpty() && tmp<=now){B+=a.last();tmp+=a.last();a.pollLast()}
                now=tmp
            }
            pl=pl xor 1
        }
        printLine("$cnt $A $B")
    }
    output()
}