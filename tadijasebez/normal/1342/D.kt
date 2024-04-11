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
    var (n,k)=readInts()
    var b=readInts().toIntArray()
    var c=readInts().toIntArray()
    var ids=Array(k){0}
    for(i in 0 until n){
        b[i]--
        ids[b[i]]++
    }
    var ans=ArrayList<ArrayList<Int>>()
    var ptr=0
    for(i in k-1 downTo 0){
        if(i==k-1 || c[i]!=c[i+1])ptr=0
        for(j in 1..ids[i]){
            while(ptr<ans.size && c[i]<=ans[ptr].size)ptr++
            if(ptr==ans.size)ans.add(ArrayList<Int>())
            ans[ptr].add(i+1)
        }
    }
    printLine("${ans.size}")
    for(i in ans)printLine(i.size.toString()+" "+i.joinToString(" "))
    output()
}