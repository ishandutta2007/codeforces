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

const val mod=998244353
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

class SegmentTree(val n:Int,val s:IntArray){
    val ls=Array(2*n){0}
    val rs=Array(2*n){0}
    var tsz=0
    var root=0
    val dp=Array(2*n){Array(4){Array(4){mod_int(0)}}}
    fun Case(mid:Int):String{
        if(s[mid-2]==1){//"<"
            if(mid==n||s[mid-1]==0)return "<"
            else return "<="
        }else{//">"
            if(mid!=n&&s[mid-1]==1)return ">"
            else return ">="
        }
    }
    fun pull(c:Int,mid:Int){
        var cs=Case(mid)
        if(cs=="<"){
            for(l1 in 0 until 4){
                for(r2 in 0 until 4){
                    dp[c][l1][r2]=mod_int(0)
                    var sum=mod_int(0)
                    for(l2 in 0 until 4){
                        dp[c][l1][r2]+=(sum*dp[rs[c]][l2][r2])
                        sum+=dp[ls[c]][l1][l2]
                    }
                    /*for(r1 in 0 until 4){
                        for(l2 in r1+1 until 4){
                            dp[c][l1][r2]=dp[c][l1][r2]+(dp[ls[c]][l1][r1]*dp[rs[c]][l2][r2])
                        }
                    }*/
                }
            }
        }else if(cs=="<="){
            for(l1 in 0 until 4){
                for(r2 in 0 until 4){
                    dp[c][l1][r2]=mod_int(0)
                    var sum=mod_int(0)
                    for(l2 in 0 until 4){
                        sum+=dp[ls[c]][l1][l2]
                        dp[c][l1][r2]+=(sum*dp[rs[c]][l2][r2])
                    }
                    /*for(r1 in 0 until 4){
                        for(l2 in r1 until 4){
                            dp[c][l1][r2]=dp[c][l1][r2]+(dp[ls[c]][l1][r1]*dp[rs[c]][l2][r2])
                        }
                    }*/
                }
            }
        }else if(cs==">"){
            for(l1 in 0 until 4){
                for(r2 in 0 until 4){
                    dp[c][l1][r2]=mod_int(0)
                    var sum=mod_int(0)
                    for(l2 in 3 downTo 0){
                        dp[c][l1][r2]+=(sum*dp[rs[c]][l2][r2])
                        sum+=dp[ls[c]][l1][l2]
                    }
                    /*for(r1 in 0 until 4){
                        for(l2 in 0 until r1){
                            dp[c][l1][r2]=dp[c][l1][r2]+(dp[ls[c]][l1][r1]*dp[rs[c]][l2][r2])
                        }
                    }*/
                }
            }
        }else{
            for(l1 in 0 until 4){
                for(r2 in 0 until 4){
                    dp[c][l1][r2]=mod_int(0)
                    var sum=mod_int(0)
                    for(l2 in 3 downTo 0){
                        sum+=dp[ls[c]][l1][l2]
                        dp[c][l1][r2]+=(sum*dp[rs[c]][l2][r2])
                    }
                    /*for(r1 in 0 until 4){
                        for(l2 in 0..r1){
                            dp[c][l1][r2]=dp[c][l1][r2]+(dp[ls[c]][l1][r1]*dp[rs[c]][l2][r2])
                        }
                    }*/
                }
            }
        }
        /*for(l1 in 0 until 4){
            for(r2 in 0 until 4){
                dp[c][l1][r2]=mod_int(0)
                for(r1 in 0 until 4){
                    for(l2 in 0 until 4){
                        if((cs=="<" && r1<l2)
                            ||(cs=="<=" && r1<=l2)
                            ||(cs==">" && r1>l2)
                            ||(cs==">=" && r1>=l2))
                            dp[c][l1][r2]=dp[c][l1][r2]+(dp[ls[c]][l1][r1]*dp[rs[c]][l2][r2])
                    }
                }
            }
        }*/
    }
    fun Build(ss:Int,se:Int):Int{
        val c=++tsz
        if(ss==se){
            for(i in 0 until 4)dp[c][i][i]=mod_int(1)
            return c
        }
        val mid=(ss+se) shr 1
        ls[c]=Build(ss,mid)
        rs[c]=Build(mid+1,se)
        pull(c,mid+1)
        return c
    }
    fun Build(){
        root=Build(1,n)
    }
    fun Set(c:Int,ss:Int,se:Int,qi:Int){
        if(ss==se)return
        var mid=(ss+se) shr 1
        if(qi<=mid)Set(ls[c],ss,mid,qi)
        else Set(rs[c],mid+1,se,qi)
        pull(c,mid+1)
    }
    fun Change(i:Int){
        s[i-1]=s[i-1] xor 1
        Set(root,1,n,i)
    }
    fun Get():Int{
        var ans=mod_int(0)
        for(l1 in 0 until 4){
            for(r1 in 0 until 4){
                ans=ans+dp[root][l1][r1]
            }
        }
        return ans.n
    }
}

fun main(){
    val(n,q)=ris()
    val s=ris()
    var st=SegmentTree(n,s.toIntArray())
    st.Build()
    for(i in 0 until q){
        val i=ri()
        st.Change(i)
        pln(st.Get())
    }
    output()
}