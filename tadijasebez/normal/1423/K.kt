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

val N=1000050

fun main(){
    val t=readInt()
    val sieve=Array(N){false}
    val primes=ArrayList<Int>()
    for(i in 2 until N){
        if(!sieve[i]){
            primes.add(i)
            for(j in i*2 until N step i)
                sieve[j]=true
        }
    }
    fun Find(x:Int):Int{
        var top=primes.size;var bot=0
        while(top>bot){
            val mid=top+bot shr 1
            if(primes[mid]<=x)bot=mid+1
            else top=mid
        }
        return bot
    }
    val ns=readInts()
    for(n in ns){
        val l=sqrt(n.toDouble()).toInt()
        val L=Find(l)
        val R=Find(n)
        printLine("${R-L+1}")
    }
    output()
}