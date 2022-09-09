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

const val L=20

class Tree(val n:Int){
    val E=Array(n+1){ArrayList<Int>()}
    init{
        repeat(n-1){
            val(u,v)=ris()
            E[u].add(v)
            E[v].add(u)
        }
    }
    val St=Array(n+1){0}
    val Ed=Array(n+1){ArrayList<ArrayList<Int>>()}
    val dep=Array(n+1){0}
    val par=Array(n+1){Array(L){0}}
    val ord=ArrayList<Int>()
    val was=Array(n+1){false}
    fun BFS(u:Int){
        val q=LinkedList<Int>()
        q.add(u)
        was[u]=true
        while(!q.isEmpty()){
            val u=q.pollFirst()
            for(i in 1 until L)par[u][i]=par[par[u][i-1]][i-1]
            dep[u]=dep[par[u][0]]+1
            ord.add(u)
            for(v in E[u])if(!was[v]){
                q.add(v)
                par[v][0]=u
                was[v]=true
            }
        }
        ord.reverse()
    }
    fun LCA(_u:Int,_v:Int):Int{
        var u=_u
        var v=_v
        if(dep[u]<dep[v])u=v.also{v=u}
        for(i in L-1 downTo 0)if(dep[par[u][i]]>=dep[v])u=par[u][i]
        for(i in L-1 downTo 0)if(par[u][i]!=par[v][i]){u=par[u][i];v=par[v][i]}
        return if(u==v)v else par[v][0]
    }
    fun Kth(_u:Int,k:Int):Int{
        var u=_u
        for(i in 0 until L)if((k shr i) and 1==1)u=par[u][i]
        return u
    }
    val dp=Array(n+1){0}
    fun DFSSolve():Long{
        var ans=0L
        for(u in ord){
            dp[u]=St[u]
            for(v in E[u])if(v!=par[u][0]){
                dp[u]+=dp[v]
            }
            for(arr in Ed[u]){
                for(v in arr)dp[v]--
                dp[u]-=arr.size
            }
            val cnt1=TreeMap<Int,Int>()
            val cnt2=TreeMap<Pair<Int,Int>,Int>(compareBy({it.first},{it.second}))
            for(arr in Ed[u]){
                ans+=dp[u]
                for(v in arr)ans-=dp[v]
            }
            var cnt=0
            for(arr in Ed[u]){
                ans+=cnt
                arr.sort()
                for(v in arr)ans-=cnt1.getOrDefault(v,0)
                cnt++
                if(arr.size==2)ans+=cnt2.getOrDefault(Pair(arr[0],arr[1]),0)
                for(v in arr)cnt1.set(v,cnt1.getOrDefault(v,0)+1)
                if(arr.size==2)cnt2.set(Pair(arr[0],arr[1]),cnt2.getOrDefault(Pair(arr[0],arr[1]),0)+1)
            }
        }
        return ans
    }
    fun Solve():Long{
        BFS(1)
        val m=ri()
        repeat(m){
            val(u,v)=ris()
            val lca=LCA(u,v)
            val arr=ArrayList<Int>()
            if(u!=lca){
                arr.add(Kth(u,dep[u]-dep[lca]-1))
                St[u]++
            }
            if(v!=lca){
                arr.add(Kth(v,dep[v]-dep[lca]-1))
                St[v]++
            }
            Ed[lca].add(arr)
        }
        return DFSSolve()
    }
}

fun main(){
    val T=Tree(ri())
    pln(T.Solve())
    output()
}