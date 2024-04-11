import java.util.*
import kotlin.math.*

fun rs()=readLine()!!
fun ri()=rs().toInt()
fun rl()=rs().toLong()
fun rd()=rs().toDouble()
fun ris()=rs().split(" ").map{it.toInt()}
fun rls()=rs().split(" ").map{it.toLong()}
fun rds()=rs().split(" ").map{it.toDouble()}

val out=mutableListOf<String>()
fun pln(s:String){out.add(s)}
fun pln(i:Int)=pln(i.toString())
fun pln(l:Long)=pln(l.toString())
fun pln(d:Double,precision:Int=12)=pln(("%."+precision.toString()+"f").format(d))
fun pln(a:IntArray)=pln(a.joinToString(" "))
fun pln(a:LongArray)=pln(a.joinToString(" "))
fun<T> pln(a:Array<T>)=pln(a.joinToString(" "))
fun<T> pln(a:ArrayList<T>)=pln(a.joinToString(" "))
fun output(){println(out.joinToString("\n"))}

fun main(){
    val t=ri()
    for(tc in 1..t){
        val n=ri()
        var mn=0
        var mx=400050
        for(i in 1..n){
            var l=rs().split(" ")
            var a=l[0]
            var b=l[1]
            var c=l[2]
            if(c[0]=='1'){
                var cnt=0
                while(cnt<a.length && cnt<b.length && a[a.length-cnt-1]==b[b.length-cnt-1]){
                    cnt++
                }
                mx=min(mx,cnt)
            }else{
                var cnt=0
                while(cnt<a.length && cnt<b.length && a[a.length-cnt-1]==b[b.length-cnt-1]){
                    cnt++
                }
                mn=max(mn,cnt+1)
            }
        }
        if(mx<mn){
            pln(0)
            continue
        }
        pln(mx-mn+1)
        var ans=ArrayList<Int>()
        for(i in mn..mx)ans.add(i)
        pln(ans)
    }
    output()
}