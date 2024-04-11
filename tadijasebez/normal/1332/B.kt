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
    var t=readInt()
    var p=intArrayOf(2,3,5,7,11,13,17,19,23,29,31)
    for(tc in 1..t){
        var n=readInt()
        var a=readInts().toIntArray()
        var c=IntArray(n){0}
        for(j in 0 until 11){
            for(i in 0 until n){
                if(a[i]%p[j]==0)c[i]=j+1
            }
        }
        var all=ArrayList<Int>()
        for(i in c)all.add(i)
        all.sort()
        all=ArrayList(all.distinct())
        for(i in 0 until n){
            c[i]=all.binarySearch(c[i])+1
        }
        printLine("${all.size}")
        printLine(c.joinToString(" "))
    }
    output()
}