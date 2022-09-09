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
        var (n,k)=readInts()
        var ans=ArrayList<Int>()
        if(k-1<n && (n-k+1)%2==1){
            for(i in 1 until k)ans.add(1)
            ans.add(n-k+1)
        }else if(2*k-2<n && (n-2*k+2)%2==0){
            for(i in 1 until k)ans.add(2)
            ans.add(n-2*k+2)
        }
        if(ans.isEmpty())printLine("NO")
        else{
            printLine("YES")
            printLine(ans.joinToString(" "))
        }
    }
    output()
}