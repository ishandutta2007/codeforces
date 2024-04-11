import java.util.*
import java.math.*
import kotlin.math.abs

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

val mod=998244353L
fun main(){
    var D=readLong()
    var i=2L
    var fs=ArrayList<Long>()
    while(i*i<=D){
        if(D%i==0L){
            fs.add(i)
            while(D%i==0L)D/=i
        }
        i++
    }
    if(D>1L)fs.add(D)
    var inv=LongArray(1000){0}
    inv[1]=1
    for(i in 2 until 1000)inv[i]=((mod-mod/i)*inv[(mod%i).toInt()])%mod
    var q=readInt()
    for(qq in 1..q){
        var (x,y)=readLongs()
        var lo=0;var hi=0
        var dv=ArrayList<Int>()
        for(i in fs){
            var bl=0
            while(x%i==0L) {
                bl++
                x /= i
            }
            while(y%i==0L){
                bl--
                y/=i
            }
            if(bl>0)hi+=bl
            else lo-=bl
            dv.add(abs(bl))
        }
        var ans=1L
        for(i in 1..lo)ans=ans*i%mod
        for(i in 1..hi)ans=ans*i%mod
        for(j in dv)for(i in 1..j)ans=ans*inv[i]%mod
        printLine("$ans")
    }
    output()
}