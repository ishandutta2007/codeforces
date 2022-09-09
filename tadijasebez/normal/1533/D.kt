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
    val(n,m)=ris()

    val go=Array(n*m+5){Array(26){0}}
    val sz=Array(n*m+5){0}
    val was=Array(n*m+5){0}
    var tsz=1
    var root=1
    fun add(s:String){
        var c=root
        for(ch in s){
            var i=ch-'a'
            if(go[c][i]==0){
                go[c][i]=++tsz
            }
            c=go[c][i]
        }
        sz[c]++
    }

    repeat(n){
        val s=rs()
        add(s)
    }
    val q=ri()
    var itr=0
    repeat(q){
        itr++
        val t=rs()
        var ans=0
        for(i in 0..m){
            var o=""
            if(i==0)o=t.substring(i+1,m+1)
            else if(i==m)o=t.substring(0,m-1+1)
            else o=t.substring(0,i-1+1)+t.substring(i+1,m+1)
            //pln(o)
            var c=root
            for(ch in o){
                var i=ch-'a'
                c=go[c][i]
            }
            if(was[c]==itr)continue
            ans+=sz[c]
            was[c]=itr
        }
        pln(ans)
    }
    output()
}