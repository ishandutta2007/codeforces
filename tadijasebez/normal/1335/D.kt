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
        var mat = arrayOfNulls<CharArray>(9)
        for(i in 0..8)
            mat[i] = readLn().toCharArray()
        var ys = intArrayOf(0,4,8,1,5,6,2,3,7)
        for(i in 0..8){
            if(mat[i]!![ys[i]]=='1')
                mat[i]!![ys[i]] = '2'
            else
                mat[i]!![ys[i]] = '1'
        }
        for(i in 0..8)
            printLine(mat[i]!!.joinToString(""))
    }
    output()
}