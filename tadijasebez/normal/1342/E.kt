import java.lang.Long.max
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

val mod=998244353L
fun mul(x:Long,y:Long):Long=x*y%mod
fun add(x:Long,y:Long):Long{
    val z=x+y
    if(z>=mod)return z-mod
    else return z
}
fun sub(x:Long,y:Long):Long{
    val z=x-y
    if(z<0L)return z+mod
    else return z
}
fun pw(_x:Long,_k:Long):Long{
    var ans=1L
    var k=_k
    var x=_x
    while(k>0){
        if(k%2L==1L)ans=mul(ans,x)
        x=mul(x,x)
        k/=2L
    }
    return ans;
}

fun main(){
    var (n,k)=readLongs()
    var F=LongArray((n+1).toInt()){1}
    var I=LongArray((n+1).toInt()){1}
    for(i in 1..n)F[i.toInt()]=mul(F[(i-1).toInt()],i)
    for(i in 2..n)I[i.toInt()]=mul((mod-mod/i),I[(mod%i).toInt()])
    for(i in 1..n)I[i.toInt()]=mul(I[i.toInt()],I[(i-1).toInt()])
    fun binom(n:Long,k:Long):Long{
        return mul(F[n.toInt()],mul(I[(n-k).toInt()],I[k.toInt()]))
    }
    if(k>=n)printLine("0")
    else{
        var m=n-k
        var ans=0L
        var bsz=0L
        for(i in m downTo 1){
            bsz=binom(n-i,m-i)
            var now=mul(mul(binom(n,i),pw(i,n)),bsz)
            if((m-i)%2L==0L){
                ans=add(ans,now)
            }else{
                ans=sub(ans,now)
            }
        }
        if(k!=0L)ans=mul(ans,2)
        printLine("$ans")
    }
    output()
}