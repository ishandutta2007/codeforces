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
 
fun main(){
    var t=readInt()
    for(tc in 1..t){
        var n=readInt()
        var a=readInts()
        var x=0
        var cnt=IntArray(n+1){0}
        for(i in 0 until n){
            x=Math.max(x,a[i])
            cnt[a[i]]++
        }
        var p=n-x
        var ok=true
        for(i in 1..p){
            if(cnt[i]!=2){
                ok=false
                break
            }
        }
        for(i in p+1..x){
            if(cnt[i]!=1){
                ok=false
                break
            }
        }
        var ans=ArrayList<IntArray>()
        if(ok){
            cnt=IntArray(n+1){0}
            for(i in 0 until p)
                cnt[a[i]]++
            ok=true
            for(i in 1..p)
                if(cnt[i]!=1)
                    ok=false
            if(ok)ans.add(intArrayOf(p,x))
            ok=true
            cnt=IntArray(n+1){0}
            for(i in 0 until x)
                cnt[a[i]]++
            for(i in 1..x)
                if(cnt[i]!=1)
                    ok=false
            if(ok && p!=x)ans.add(intArrayOf(x,p))
        }
        printLine(ans.size.toString())
        for(i in ans)
            printLine(i.joinToString(" "))
    }
    output()
}