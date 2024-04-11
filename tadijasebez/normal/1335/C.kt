import java.util.*
import java.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts()  = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs()  = readLn().split(" ").map{it.toLong()}

val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }

fun main(){
    var t = readInt()
    for(tc in 1..t){
        var n = readInt()
        var a = readInts()
        var cnt = IntArray(n+1)
        for(x in a){
            cnt[x]++
        }
        var dif = 0
        for(i in 1..n){
            if(cnt[i]>0)
                dif++
        }
        var ans = 0
        for(i in 1..n){
            ans=Math.max(ans,Math.min(cnt[i],dif-1))
            ans=Math.max(ans,Math.min(cnt[i]-1,dif))
        }
        printLine(ans.toString())
    }
    output()
}