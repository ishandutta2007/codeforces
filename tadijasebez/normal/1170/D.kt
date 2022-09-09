import java.util.*
import java.math.*
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts()  = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs()  = readLn().split(" ").map{it.toLong()}

val out = mutableListOf<String>()
fun printLine(s: String){
    out.add(s)
}
fun output() {
    println(out.joinToString("\n"))
}
 
fun main(){
	var m = readInt()
    var b = readInts()
    var n = 0
    for(i in 0..m-1)
        if(b[i]==-1)
            n++
    var idx = IntArray(n)
    var k = n
    for(i in 0..n-1)
        idx[i]=i
    var ans = Array(n,{ArrayList<Int>()})
    var j = 0
    while(j<m){
        var p = 0
        for(i in 0..k-1){
            if(b[j]!=-1){
                ans[idx[i]].add(b[j])
                idx[p] = idx[i]
                p++
            }
            j++;
        }
        k = p
    }
    printLine(n.toString())
    for(i in 0..n-1){
        printLine(ans[i].size.toString()+" "+ans[i].joinToString(" "))
    }
    output()
}