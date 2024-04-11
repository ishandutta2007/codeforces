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
    var (n,k)=readInts()
    var AB=ArrayList<Int>()
    var A=ArrayList<Int>()
    var B=ArrayList<Int>()
    for(i in 0 until n){
        var (t,a,b)=readInts()
        if(a==1&&b==1)AB.add(t)
        else if(a==1)A.add(t)
        else if(b==1)B.add(t)
    }
    AB.sort()
    A.sort()
    B.sort()
    var X=ArrayList<Int>()
    var Y=ArrayList<Int>()
    X.add(0)
    for(i in AB)X.add(X.last()+i)
    Y.add(0)
    for(i in 0 until min(A.size,B.size))Y.add(Y.last()+A[i]+B[i])
    var ans=-1
    for(i in 0..k){
        if(X.size>i&&Y.size>k-i){
            var now=X[i]+Y[k-i]
            if(ans==-1||ans>now)ans=now
        }
    }
    printLine("$ans")
    output()
}