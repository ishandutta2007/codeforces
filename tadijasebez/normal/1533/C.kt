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
        val(n,k)=ris()
        val like=rs()
        var good=0
        for(i in like){
            if(i=='1')good++
        }
        if(good==0){
            pln(0)
            continue
        }
        if(like[0]=='1')good--
        val a=Array(n-1){it+2}
        var len=n-1
        val ans=ArrayList<Int>()
        ans.add(1)
        var i=0
        while(len>0&&good>0){
            var cnt=k
            while(cnt>1){
                cnt--
                i++
                i%=len
            }
            ans.add(a[i])
            if(like[a[i]-1]=='1')good--
            for(j in i..len-2){
                a[j]=a[j+1]
            }
            len--
            if(i==len)i=0
        }
        pln(ans.size)
    }
    output()
}