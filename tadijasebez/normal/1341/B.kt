//juzinije od duse nesto me bas zaboli
//tebe neka drugi takvu zavoli

import java.util.*
import java.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{it.toLong()}

val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }

fun main(){
    var t=readInt()
    for(tc in 1..t){
        var (n,k)=readInts()
        var a=readInts().toIntArray()
        var b=IntArray(n){0}
        for(i in 1 until n-1){
            if(a[i]>a[i-1] && a[i]>a[i+1])b[i]=1
            b[i]+=b[i-1]
        }
        var ans=-1
        var pos=-1
        for(i in 0..n-k){
            var sum=b[i+k-2]-b[i]
            if(ans<sum){
                ans=sum
                pos=i
            }
        }
        printLine("${ans+1} ${pos+1}")
    }
    output();
}