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

class LowestCommonAncestor(val E:Array<ArrayList<Int>>,val L:Int){
    val n=E.size
    var sz=Array(n){0};var par=Array(n){Array(L){-1}};var ptr=Array(n){0}
    var lid=Array(n){0};var rid=Array(n){0};var dep=Array(n){0}
    fun DFS(root:Int){
        ptr=Array(n){0};par=Array(n){Array(L){-1}};dep=Array(n){0}
        val stk=Stack<Int>();var tid=0
        stk.push(root)
        while(stk.isNotEmpty()){
            val u=stk.pop()
            if(ptr[u]==0){
                sz[u]=1
                lid[u]=tid++
            }
            if(ptr[u]==E[u].size){
                if(par[u][0]!=-1)sz[par[u][0]]+=sz[u]
                rid[u]=tid-1
            }else{
                val v=E[u][ptr[u]++]
                if(v==par[u][0]){stk.push(u);continue}
                par[v][0]=u;dep[v]=dep[u]+1
                for(i in 1 until L)if(par[v][i-1]!=-1)par[v][i]=par[par[v][i-1]][i-1]
                stk.push(u)
                stk.push(v)
            }
        }
    }
    fun LCA(_u:Int,_v:Int):Int{
        var u=_u;var v=_v
        if(dep[u]<dep[v])u=v.also{v=u}
        for(i in L-1 downTo 0)if(par[u][i]!=-1&&dep[par[u][i]]>=dep[v])u=par[u][i]
        for(i in L-1 downTo 0)if(par[u][i]!=par[v][i]){u=par[u][i];v=par[v][i]}
        return if(u==v)v else par[v][0]
    }
}

fun main(){
    val n=ri()
    val E=Array(n){ArrayList<Int>()}
    data class Edge(val u:Int,val v:Int)
    val edges=Array(n){Edge(0,0)}
    for(i in 1 until n){
        var(u,v)=ris();u--;v--
        edges[i]=Edge(u,v)
        E[u].add(v);E[v].add(u)
    }
    val LCA=LowestCommonAncestor(E,17)
    LCA.DFS(0)
    val m=ri()
    val sum=Array(n){0}
    for(i in 0 until m){
        var(u,v)=ris();u--;v--
        val lca=LCA.LCA(u,v)
        sum[u]++;sum[v]++;sum[lca]-=2
    }
    val par=Array(n){-1};val ptr=Array(n){0}
    val stk=Stack<Int>()
    stk.push(0)
    while(stk.isNotEmpty()){
        val u=stk.pop()
        if(ptr[u]!=E[u].size){
            val v=E[u][ptr[u]++]
            if(v==par[u]){stk.push(u);continue}
            par[v]=u
            stk.push(u)
            stk.push(v)
        }else if(par[u]!=-1)sum[par[u]]+=sum[u]
    }
    val ans=Array(n-1){0}
    for(i in 1 until n){
        var(u,v)=edges[i]
        if(par[u]!=v)u=v
        ans[i-1]=sum[u]
    }
    pln(ans)
    output()
}