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
    var (n,t)=readInts()
    var str=readLn().toCharArray()
    repeat(t){
        var sw=false
        for(i in 1 until n){
            if(!sw&&str[i]=='G'&&str[i-1]=='B'){
                sw=true
                str[i]=str[i-1].also{str[i-1]=str[i]}
            }else sw=false
        }
    }
    printLine(str.joinToString(""))
    output()
}