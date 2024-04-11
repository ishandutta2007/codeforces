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
        var (n0,n1,n2)=readInts()
        var ans=ArrayList<Char>()
        if(n0==0 && n1==0){
            for(i in 0..n2)ans.add('1')
        }else if(n1==0 && n2==0){
            for(i in 0..n0)ans.add('0')
        }else{
            for(i in 0..n0)ans.add('0')
            ans.add('1')
            for(i in 1..n2)ans.add('1')
            for(i in 1 until n1){
                ans.add(if(ans.last()=='0')'1' else '0')
            }
        }
        printLine(ans.joinToString(""))
    }
    output()
}