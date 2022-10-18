import java.util.PriorityQueue
fun readln() = readLine()!!
fun readint() = readln().toInt() 
fun readlong() = readln().toLong() 
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() } 
fun readlongs() = readstrings().map { it.toLong() } 
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
	var n = readint()
   	var a = readlongs()
    var mx=0L
    var pos=0
   	for(i in 0 until n){
        if(mx<=a[i]){
            mx = a[i]
            pos=i
        }
    }
    var ans = (mx-1L)*n.toLong()
    ans+=pos+1
    println(ans)
}