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
val M=1000050
val L=18
var st=Array(N){Array(L){0}}
var lgs=Array(N){0}
fun gcd(x:Int,y:Int):Int=if(x==0)y else gcd(y%x,x)
fun Get(l:Int,_r:Int):Int{
    var r=_r-1;var k=lgs[r-l+1]
    return gcd(st[l][k],st[r-(1 shl k)+1][k])
}
fun main(){
    var (k,n)=readInts()
    var p=readInts().toIntArray()
    var x=readInts().toIntArray()
    for(i in 0 until n-1){
        st[i][0]=x[i+1]-x[i]
    }
    for(j in 1 until L){
        for(i in 0 until (N-(1 shl j)+1)){
            st[i][j]=gcd(st[i][j-1],st[i+(1 shl (j-1))][j-1])
        }
    }
    for(i in 2..n)lgs[i]=lgs[i/2]+1
    var idx=Array(M){-1}
    for(i in 0 until n)idx[x[i]]=i
    var has=Array(M){0}
    for(i in p){
        for(j in i until M step i)has[j]=i
    }
    var ans=Pair(-1,-1)
    for(gap in p){
        var ids=ArrayList<Int>()
        for(i in x[0] until M step gap){
            if(idx[i]!=-1)ids.add(idx[i])
        }
        var las=-1;var g=0
        ids.add(n)
        for(i in 1 until ids.size){
            var A=ids[i-1];var B=ids[i]
            if(A+1<B){
                if(A+1<B-1)g=gcd(g,Get(A+1,B-1))
                if(las!=-1)g=gcd(g,x[A+1]-x[las])
                las=B-1
            }
        }
        if(g==0){ans=Pair(gap,gap);break}
        else if(has[g]!=0){ans=Pair(gap,has[g]);break}
    }
    if(ans.first!=-1){
        printLine("YES")
        var st2=x[0]
        for(i in x){
            if((i-x[0])%ans.first!=0){
                st2=i
                break
            }
        }
        printLine("${x[0]} ${ans.first}")
        printLine("$st2 ${ans.second}")
    }else printLine("NO")
    output()
}