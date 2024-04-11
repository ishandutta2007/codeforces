import java.util.*
import java.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun gcd(a:Long,b:Long):Long{
    if(a==0L)return b
    else return gcd(b%a,a)
}

fun main(){
    var t=readInt()
    for(tc in 1..t){
        var (a,b,q)=readLongs()
        var blk=a*b/gcd(a,b)
        var o=ArrayList<Long>()
        var pos=ArrayList<Long>()
        for(j in 0 until blk){
            if((j%a)%b==(j%b)%a){
                pos.add(j)
            }
        }
        for(i in 1..q){
            var ans=0L
            var (l,r)=readLongs()
            for(j in pos){
                if(r-j<0)ans--
                else ans+=(r-j)/blk
                if(l-j-1<0)ans++
                else ans-=(l-j-1)/blk
            }
            o.add(r-l+1-ans)
        }
        printLine(o.joinToString(" "))
    }
    output()
}