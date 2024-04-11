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
        var (a,b,c,d)=readInts()
        var tmp=readInts()
        var x=tmp[0]
        var y=tmp[1]
        var xl=tmp[2]
        var yl=tmp[3]
        var xr=tmp[4]
        var yr=tmp[5]
        x+=b-a
        y+=d-c
        var ok=false
        if(xl<=x && x<=xr && yl<=y && y<=yr)
            ok=true
        if(xl==xr && a+b>0)
            ok=false
        if(yl==yr && c+d>0)
            ok=false
        if(ok)
            printLine("YES")
        else
            printLine("NO")
    }
    output()
}