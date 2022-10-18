import java.util.*
fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = readln().split(" ")
fun readints() = readstrings().map { it.toInt() }
fun readlongs() = readstrings().map { it.toLong() }
fun readdoubles() = readstrings().map { it.toDouble() }

fun main() {
    var tt=readint()
    while(tt-- > 0){
        var (nn,s)=readlongs()
        var n=nn.toInt()
        var edges=IntArray(n-1)
        var cost=LongArray(n-1)
        var mul=LongArray(n-1)
        var t=LongArray(n)
        var g=Array(n){mutableListOf<Int>()}
        for(i in 0..n-2){
            var(uu,vv,w)=readlongs()
            var u=uu.toInt()
            var v=vv.toInt()
            u--
            v--
            edges[i]=(u+v)
            cost[i]=w
            g[u].add(i)
            g[v].add(i)
        }
        fun dfs(v:Int,p:Int){
            for(id in g[v]){
                var to=edges[id]-v
                if(to==p){
                    continue
                }
                dfs(to,v)
                mul[id]=t[to]
                t[v]+=t[to]
            }
            t[v]=maxOf(t[v],1L)
        }
        dfs(0,-1)
        var sum=0L
        var a=mutableListOf<Long>()
        for(i in 0..n-2){
            sum+=cost[i]*mul[i]
            while(cost[i]>0L){
                a.add(cost[i]*mul[i]-cost[i]/2L*mul[i])
                cost[i]/=2L
            }
        }
        a.sortWith(compareBy({-it}))
        var ans=0
        while(sum>s){
            sum-=a[ans]
            ans++
        }
        println(ans)
    }
}