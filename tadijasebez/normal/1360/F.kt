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
        val (n,m)=readInts()
        val a=ArrayList<String>()
        repeat(n){a.add(readLn())}
        fun check(b:String):Boolean{
            for(str in a){
                var dif=0
                for(i in 0 until m)if(str[i]!=b[i])dif++
                if(dif>1)return false
            }
            return true
        }
        var ans="-1"
        if(check(a[0]))ans=a[0]
        for(j in 0 until m){
            for(i in 1 until n){
                val str=a[0].toCharArray()
                str[j]=a[i][j]
                if(check(str.joinToString("")))ans=str.joinToString("")
            }
        }
        printLine(ans)
    }
    output()
}