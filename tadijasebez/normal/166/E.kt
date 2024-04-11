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

const val mod=1000000007
class mod_int(var n:Int=0){
    operator fun plus(b:mod_int):mod_int{
        var ans=n+b.n
        if(ans>=mod)ans-=mod
        return mod_int(ans)
    }
    operator fun minus(b:mod_int):mod_int{
        var ans=n-b.n
        if(ans<0)ans+=mod
        return mod_int(ans)
    }
    operator fun times(b:mod_int)=mod_int((n.toLong()*b.n%mod).toInt())
    fun exp(_k:Long):mod_int{
        var k=_k;var ans=mod_int(1);var x=this
        while(k>0){
            if(k%2==1.toLong())ans*=x
            x*=x
            k/=2
        }
        return ans
    }
    fun inv()=this.exp(mod.toLong()-2)
    operator fun div(b:mod_int)=this*b.inv()
    override fun toString()=n.toString()
}

class Vector(val n:Int){
    var a=Array(n){mod_int()}
    fun cl(){a=Array(n){mod_int()}}
    fun set(b:Array<Int>){
        for(i in 0 until n)a[i]=mod_int(b[i])
    }
}

class Matrix(val n:Int){
    var a=Array(n){Array(n){mod_int()}}
    operator fun get(i:Int,j:Int)=a[i][j]
    operator fun set(i:Int,j:Int,x:mod_int){a[i][j]=x}
    fun cl(){a=Array(n){Array(n){mod_int()}}}
    fun id(){cl();for(i in 0 until n)a[i][i]=mod_int(1)}
    fun set(b:Array<Array<Int>>){
        for(i in 0 until n)for(j in 0 until n)a[i][j]=mod_int(b[i][j])
    }
    operator fun plus(other:Matrix):Matrix{
        val ans=Matrix(n)
        for(i in 0 until n)for(j in 0 until n)ans.a[i][j]=a[i][j]+other.a[i][j]
        return ans
    }
    operator fun minus(other:Matrix):Matrix{
        val ans=Matrix(n)
        for(i in 0 until n)for(j in 0 until n)ans.a[i][j]=a[i][j]-other.a[i][j]
        return ans
    }
    operator fun times(other:Matrix):Matrix{
        val ans=Matrix(n)
        for(i in 0 until n)for(j in 0 until n)for(k in 0 until n)ans.a[i][j]+=a[i][k]*other.a[k][j]
        return ans
    }
    operator fun times(other:Vector):Vector{
        val ans=Vector(n)
        for(i in 0 until n)for(j in 0 until n)ans.a[i]+=a[i][j]*other.a[j]
        return ans
    }
}

fun main(){
    val n=ri()
    var m=Matrix(4)
    m.set(arrayOf(arrayOf(0,1,1,1),arrayOf(1,0,1,1),arrayOf(1,1,0,1),arrayOf(1,1,1,0)))
    var v=Vector(4)
    v.set(arrayOf(1,0,0,0))
    for(i in 0 until 30){
        if((n shr i) and 1 == 1){
            v=m*v
        }
        m*=m
    }
    pln(v.a[0].n)
    output()
}