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
    var (n,m,k)=readInts()
    var mxx=0;var mxy=0
    for(i in 1..k){
        var (x,y)=readInts()
        mxx=max(mxx,x);mxy=max(mxy,y)
    }
    for(i in 1..k){var (x,y)=readInts()}
    var ans=ArrayList<Char>()
    for(i in 1 until mxx)ans.add('U')
    for(i in 1 until mxy)ans.add('L')
    for(i in 1..n){
        var ch=if(i%2==1)'R' else 'L'
        for(j in 1 until m)ans.add(ch)
        if(i!=n)ans.add('D')
    }
    printLine("${ans.size}")
    printLine(ans.joinToString(""))
    output()
}