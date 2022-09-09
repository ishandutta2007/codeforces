import java.security.SecureRandom
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
    val n=readInt()
    val a=readLongs()
    val prime=Array<Boolean>(N){true}
    val ps=ArrayList<Int>()
    for(i in 2 until N){
        if(prime[i]) {
            ps.add(i)
            for (j in i*2 until N step i)
                prime[j]=false
        }
    }
    var ans=n.toLong()
    fun Work(p:Long){
        var now=0L
        for(i in a){
            if(i<p)now+=p-i
            else now+=min(i%p,p-i%p)
        }
        ans=min(ans,now)
    }
    fun Consider(_x:Long){
        var x=_x
        for(p in ps){
            if(p*p>x)break
            if(x%p==0L)Work(p.toLong())
            while(x%p==0L)x/=p
        }
        if(x>1L)Work(x)
    }
    val rng=SecureRandom()
    for(itr in 1..20){
        val idx=rng.nextInt(n)
        Consider(a[idx])
        Consider(a[idx]+1L)
        if(a[idx]>1L)Consider(a[idx]-1L)
    }
    printLine("$ans")
    output()
}