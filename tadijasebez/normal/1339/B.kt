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
    var t = readInt()
    for(tt in 1..t){
        var n = readInt()
        var a = readInts().toIntArray()
        a.sort()
        var l = (n-1)/2
        var r = l+1
        var ans = ArrayList<Int>()
        if(n%2==1){
            ans.add(a[l])
            l--
        }
        while(l>=0){
            ans.add(a[l])
            ans.add(a[r])
            l--
            r++
        }
        printLine(ans.joinToString(" "))
    }
    output()
}