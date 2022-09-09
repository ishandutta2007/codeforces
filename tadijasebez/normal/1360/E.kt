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
        var mat=Array(n+1){if(it<n)readLn()+"1" else ""}
        repeat(n+1){mat[n]+="1"}
        var ok=true
        for(i in 0 until n){
            for(j in 0 until n){
                if(mat[i][j]=='1'&&!(mat[i][j+1]=='1'||mat[i+1][j]=='1'))ok=false
            }
        }
        printLine(if(ok)"YES" else "NO")
    }
    output()
}