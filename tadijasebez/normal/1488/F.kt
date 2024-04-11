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
    val n=ri()
    val _c=ris()
    val c=Array(n+1){if(it==0)0 else _c[it-1]}
    val q=ri()
    val ql=Array(q){0}
    val qr=Array(q){0}
    val ans=Array(q){0L}
    val Qs=Array(n+1){ArrayList<Int>()}
    for(i in 0 until q){
        val(l,r)=ris()
        ql[i]=l
        qr[i]=r
        Qs[r].add(i)
    }
    val dp=ArrayList<Long>()
    val stk=ArrayList<Int>()
    c[0]=100000000
    stk.add(0)
    dp.add(0L)
    for(i in 1..n){
        while(stk.size>1&&c[stk.last()]<=c[i]){
            stk.removeAt(stk.size-1)
            dp.removeAt(dp.size-1)
        }
        dp.add(dp.last()+(i-stk.last()).toLong()*c[i])
        stk.add(i)
        //pln("$i $dp")
        for(qi in Qs[i]){
            var top=stk.size-1
            var bot=0
            var ptr=0
            while(top>=bot){
                var mid=(bot+top) shr 1
                if(stk[mid]<ql[qi]){ptr=mid;bot=mid+1}
                else top=mid-1
            }
            //pln("$qi $ptr ${stk[ptr]} ${dp.last()}")
            ans[qi]=dp.last()-dp[ptr]
            ans[qi]-=(stk[ptr+1]-stk[ptr]).toLong()*c[stk[ptr+1]]
            ans[qi]+=(stk[ptr+1]-ql[qi]+1).toLong()*c[stk[ptr+1]]
        }
    }
    pln(ans)
    output()
}