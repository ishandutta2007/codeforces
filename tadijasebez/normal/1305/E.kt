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
    var (n,m)=readInts()
    var mx=0
    for(i in 0 until n)mx+=i/2
    if(m>mx)printLine("-1")
    else{
        var j=0
        val ans=ArrayList<Int>()
        for(i in 0 until n){
            if(m>j/2){
                m-=j/2
                ans.add(i+1)
                j=i+1
            }
            else break
        }
        ans.add(j*2+1-m*2)
        for(i in 0 until n-j-1)ans.add(100000000+10000*(i+1))
        printLine(ans.joinToString(" "))
    }
    output()
}