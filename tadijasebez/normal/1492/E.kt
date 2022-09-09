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
    val s=Array(n){ris().toIntArray()}
    fun Diff(a:IntArray,b:IntArray):Int{
        var ans=0
        for(i in 0 until m)if(a[i]!=b[i])ans++
        return ans
    }
    fun Check(a:IntArray):Boolean{
        for(b in s){
            if(Diff(a,b)>2)return false
        }
        return true
    }
    if(Check(s[0])){
        pln("Yes")
        pln(s[0])
    }else{
        var ans=IntArray(0)
        for(i in 1 until n){
            val diff=Diff(s[0],s[i])
            if(diff>4)break
            if(diff==4){
                val pos=ArrayList<Int>()
                for(j in 0 until m){
                    if(s[0][j]!=s[i][j])pos.add(j)
                }
                for(j in 0 until 4){
                    for(k in j+1 until 4){
                        val c=IntArray(m){if(it==pos[j]||it==pos[k])s[i][it] else s[0][it]}
                        if(Check(c)){
                            ans=c
                            break
                        }
                    }
                    if(ans.size!=0)break
                }
                break
            }else if(diff==3){
                val pos=ArrayList<Int>()
                for(j in 0 until m){
                    if(s[0][j]!=s[i][j])pos.add(j)
                }
                for(j in 0 until 3){
                    for(k in 0 until 3)if(j!=k){
                        val z=pos[3-k-j]
                        val c=IntArray(m){if(it==pos[j])s[i][it] else s[0][it]}
                        for(l in 0 until n){
                            var cnt=0
                            for(r in 0 until m)if(r!=z){
                                if(s[l][r]!=c[r])cnt++
                            }
                            if(cnt>=2)c[z]=s[l][z]
                        }
                        if(Check(c)){
                            ans=c
                            break
                        }
                    }
                    if(ans.size!=0)break
                }
                break
            }
            if(ans.size!=0)break
        }
        if(ans.size==0){
            pln("No")
        }else{
            pln("Yes")
            pln(ans)
        }
    }
    output()
}