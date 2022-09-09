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

val N=100050
val M=4*N
var mx=Array(M){0}
var lzy=Array(M){0}
fun Add(c:Int,ss:Int,se:Int,qs:Int,qe:Int,x:Int){
    if(qs>qe||qs>se||ss>qe)return
    if(qs<=ss&&qe>=se){mx[c]+=x;lzy[c]+=x;return}
    var mid=(ss+se)/2
    Add(c*2,ss,mid,qs,qe,x)
    Add(c*2+1,mid+1,se,qs,qe,x)
    mx[c]=max(mx[c*2],mx[c*2+1])+lzy[c]
}
fun main(){
    var n=readInt()
    var a=ArrayList(readInts())
    var stk=Stack<Int>()
    stk.push(0)
    var ans=0
    for(i in 1..n){
        var x=a[i-1]
        while(stk.size>1&&a[stk.last()-1]<x){
            var y=stk.pop()
            Add(1,1,n,stk.last()+1,y,a[y-1])
        }
        Add(1,1,n,stk.last()+1,i,-x)
        Add(1,1,n,1,i,x)
        stk.push(i)
        ans=max(ans,mx[1]);
    }
    printLine("$ans")
    output()
}