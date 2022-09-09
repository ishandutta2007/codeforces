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

fun ArrayList<Long>.get_lo(x:Long):Int{
    var idx=this.binarySearch(x)
    if(idx>=0)return idx+1
    else return -idx-1
}
fun Long.toBinaryString(m:Int):String{
    var ans="";var tmp=this
    repeat(m){ans=('0'+(tmp%2).toInt())+ans;tmp/=2}
    return ans
}
fun main(){
    val t=readInt()
    repeat(t){
        var (n,m)=readInts()
        var a=ArrayList<Long>()
        fun make(str:String):Long{
            var ans=0L
            for(i in str)ans=ans*2+(i-'0')
            return ans
        }
        repeat(n){a.add(make(readLn()))}
        a.sort()
        var lo=((1L shl m)-n-1)/2
        var top=(1L shl m)-1;var bot=0L;var pos=-1L
        while(top>=bot){
            var mid=(top+bot)/2
            var cnt=mid+1-a.get_lo(mid)
            if(cnt<=lo){pos=mid;bot=mid+1}
            else top=mid-1
        }
        printLine((pos+1).toBinaryString(m))
    }
    output()
}