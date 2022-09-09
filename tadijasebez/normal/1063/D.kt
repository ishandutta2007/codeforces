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

fun dv1(p:Long,q:Long):Long=if(p>=0)(p+q-1)/q else p/q
fun dv2(p:Long,q:Long):Long=if(p>=0)p/q else (p-q+1)/q
fun main(){
    val (n,l,r,k)=readLongs()
    val x=if(l<=r)r-l+1 else r+n-l+1
    val y=n-x;var ans=-1L
    if(n<k/n/n){
        for(a in 0..x){
            for(b in 0..y){
                val p=k-x-a;val q=x+a+y+b
                if(p%q==0L)ans=max(ans,a+b)
                if(a>0&&(p+1)%q==0L)ans=max(ans,a+b)
            }
        }
    }else{
        for(t in 0..k/n){
            if(t==0L){
                if(k>=x&&k<=x*2)ans=max(ans,y+k-x)
                if(k>=x&&k+1<=x*2)ans=max(ans,y+k+1-x)
            }else{
                var m=k-(t+1)*x-t*y
                if(m<0)continue
                var p=m;var q=-m
                var mn=max(dv1(-q,t+1),dv1(p-x,t))
                var mx=min(dv2(p,t),dv2(y-q,t+1))
                if(mn<=mx)ans=max(ans,p-t*mx+q+(t+1)*mx)
                m++;p=m;q=-m
                mn=max(dv1(-q,t+1),dv1(p-x,t))
                mx=min(dv2(p-1,t),dv2(y-q,t+1))
                if(mn<=mx)ans=max(ans,p-t*mx+q+(t+1)*mx)
            }
        }
    }
    printLine("$ans")
    output()
}