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
    var n=readInt()
    var a=readInts().toIntArray()
    var mx=a[0];var mn=a[0]
    for(i in a){
        mx=max(mx,i)
        mn=min(mn,i)
    }
    var ans=0
    for(i in 0 until n){
        if(a[i]==mx){
            for(j in i downTo 1){
                ans++
                a[j]=a[j-1].also{a[j-1]=a[j]}
            }
            break
        }
    }
    for(i in n-1 downTo 0){
        if(a[i]==mn){
            for(j in i until n-1){
                ans++
                a[j]=a[j+1].also{a[j+1]=a[j]}
            }
            break
        }
    }
    printLine("$ans")
    output()
}