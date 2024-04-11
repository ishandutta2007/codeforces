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
    var x=readInt()
    var y=x+1
    while(true){
        var st=ArrayList<Int>()
        var tmp=y
        while(tmp>0){
            st.add(tmp%10)
            tmp/=10
        }
        st.sort()
        var ok=true
        for(i in 1 until st.size){
            if(st[i]==st[i-1])ok=false
        }
        if(ok)break
        y++
    }
    printLine("$y")
    output()
}