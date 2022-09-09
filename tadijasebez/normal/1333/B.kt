import java.util.*
import java.math.*
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts()  = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs()  = readLn().split(" ").map{it.toLong()}

fun main(){
    var t = readInt()
    while(t --> 0){
        var n = readInt()
        var a = readInts()
        var b = readInts()
        var mn = IntArray(n)
        var mx = IntArray(n)
        mn[0]=0
        mx[0]=0
        for(i in 1..n-1){
            mn[i] = Math.min(mn[i - 1], a[i - 1])
            mx[i] = Math.max(mx[i - 1], a[i - 1])
        }
        var ok = true
        for(i in n-1 downTo 0){
            if(b[i] < a[i] && mn[i] != -1)
                ok = false
            if(b[i] > a[i] && mx[i] !=  1) 
                ok = false
        }
        if(ok) 
            println("YES")
        else 
            println("NO")
    }
}