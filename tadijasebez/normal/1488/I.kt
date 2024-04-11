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

const val inf=1e9.toInt()

/*class Dinic(val n:Int){
    data class Edge(val u:Int,val v:Int,var c:Int,var f:Int,var rev:Edge?,var nxt:Edge?)
    val E=Array<Edge?>(n+1){null}
    fun addEdge(u:Int,v:Int,c:Int){
        val E1=Edge(u,v,c,0,null,E[u])
        val E2=Edge(v,u,0,0,E1,E[v])
        E1.rev=E2
        E[u]=E1
        E[v]=E2
    }
    var dist=Array(n+1){inf}
    private fun BFS(s:Int,t:Int):Boolean{
        dist=Array(n+1){inf}
        val q=LinkedList<Int>()
        q.add(s)
        dist[s]=0
        while(q.isNotEmpty()){
            val u=q.remove()
            var e=E[u]
            while(e!=null){
                if(e.c>e.f&&dist[e.v]==inf){
                    dist[e.v]=dist[u]+1
                    q.push(e.v)
                }
                e=e.nxt
            }
        }
        return dist[t]!=inf
    }
    var ptr=Array<Edge?>(n+1){null}
    private fun DFS(u:Int,_flow:Int,t:Int):Int{
        var flow=_flow
        if(u==t||flow==0)return flow
        if(dist[u]>dist[t])return 0
        var ans=0
        while(ptr[u]!=null){
            val e=ptr[u]!!
            if(e.c==e.f||dist[e.v]!=dist[u]+1){
                ptr[u]=e.nxt
                continue
            }
            val cut=DFS(e.v,min(flow,e.c-e.f),t)
            ans+=cut
            flow-=cut
            e.f+=cut
            e.rev!!.f-=cut
            if(flow==0){
                return ans
            }
            ptr[u]=e.nxt
        }
        return ans
    }
    fun maxFLow(s:Int,t:Int):Int{
        var ans=0
        while(BFS(s,t)){
            ptr=Array(n+1){E[it]}
            ans+=DFS(s,inf,t)
        }
        return ans
    }
}*/

internal object Flow {
    var n = 0
    var edgesLen: IntArray? = null
    var edges: Array<IntArray>? = null
    var capsLen = 0
    var caps: IntArray? = null
    fun init() {
        edgesLen = IntArray(n)
        edges = Array(n) { IntArray(6) }
        capsLen = 0
        caps = IntArray(6)
    }

    fun addEdge(from: Int, to: Int, capacity: Int, reverseCapacity: Int): Int {
        val cap = capsLen
        if (caps!!.size == cap) {
            caps = Arrays.copyOf(caps, (cap shl 1) + 2)
        }
        caps!![cap] = capacity
        caps!![cap + 1] = reverseCapacity
        capsLen = cap + 2
        var e1s = edges!![from]
        val e1 = edgesLen!![from]
        if (e1s.size == e1) {
            edges!![from] = Arrays.copyOf(e1s, (e1 shl 1) + 2)
            e1s = edges!![from]
        }
        e1s[e1] = to
        e1s[e1 + 1] = cap
        edgesLen!![from] = e1 + 2
        var e2s = edges!![to]
        val e2 = edgesLen!![to]
        if (e2s.size == e2) {
            edges!![to] = Arrays.copyOf(e2s, (e2 shl 1) + 2)
            e2s = edges!![to]
        }
        e2s[e2] = from
        e2s[e2 + 1] = cap + 1
        edgesLen!![to] = e2 + 2
        return cap
    }

    fun dinic(source: Int, sink: Int): Int {
        val dist = IntArray(n)
        val curEdge = IntArray(n)
        val queue = IntArray(n)
        var flow = 0
        while (true) {
            Arrays.fill(dist, -1)
            dist[source] = 0
            queue[0] = source
            var queueHead = 0
            var queueTail = 1
            do {
                val cur = queue[queueHead++]
                val ndist = dist[cur] + 1
                var i = 0
                val e = edges!![cur]
                val en = edgesLen!![cur]
                while (i < en) {
                    if (caps!![e[i + 1]] == 0) {
                        i += 2
                        continue
                    }
                    val to = e[i]
                    if (dist[to] < 0) {
                        dist[to] = ndist
                        queue[queueTail++] = to
                    }
                    i += 2
                }
            } while (queueHead < queueTail)
            if (dist[sink] < 0) {
                return flow
            }
            Arrays.fill(curEdge, 0)
            var stackSize = 0
            var cur = source
            var eNum = 0
            cur@ while (true) {
                if (cur == sink) {
                    var curFlow = Int.MAX_VALUE
                    for (i in 0 until stackSize) {
                        val c = queue[i]
                        curFlow = Math.min(curFlow, caps!![edges!![c][curEdge[c] + 1]])
                    }
                    for (i in 0 until stackSize) {
                        val c = queue[i]
                        val cap = edges!![c][curEdge[c] + 1]
                        caps!![cap] -= curFlow
                        caps!![cap xor 1] += curFlow
                    }
                    flow += curFlow
                    stackSize = 0
                    cur = source
                    eNum = curEdge[source]
                    continue
                }
                val ndist = stackSize + 1
                val e = edges!![cur]
                val en = edgesLen!![cur]
                while (eNum < en) {
                    val next = e[eNum]
                    if (caps!![e[eNum + 1]] != 0 && dist[next] == ndist) {
                        curEdge[cur] = eNum
                        queue[stackSize++] = cur
                        cur = next
                        eNum = curEdge[cur]
                        continue@cur
                    }
                    eNum += 2
                }
                curEdge[cur] = eNum
                if (stackSize == 0) {
                    break
                }
                cur = queue[--stackSize]
                eNum = curEdge[cur] + 2
            }
        }
    }
}

class Graph(val n:Int,val m:Int){
    data class Edge(val v:Int,val i:Int)
    val E=Array(n+1){ArrayList<Edge>()}
    init{
        for(i in 1..m){
            val(u,v)=ris()
            E[u].add(Edge(v,i))
            E[v].add(Edge(u,i))
        }
    }
    fun Solve():Int{
        val dist=Array(n+1){inf}
        val q=LinkedList<Int>()
        q.add(1)
        dist[1]=0
        val s=n+m+1
        val t=n+m+2
        //val fn=Dinic(n+m+2)
        Flow.n=n+m+3
        Flow.init()
        while(!q.isEmpty()){
            val u=q.remove()
            for(e in E[u]){
                if(dist[e.v]==inf){
                    dist[e.v]=dist[u]+1
                    q.add(e.v)
                }else if(dist[e.v]+1==dist[u]){
                    if(dist[u]%2==0){
                        Flow.addEdge(s,n+e.i,1,0)
                        Flow.addEdge(n+e.i,u,1,0)
                        Flow.addEdge(n+e.i,e.v,1,0)
                    }else{
                        Flow.addEdge(n+e.i,t,1,0)
                        Flow.addEdge(u,n+e.i,1,0)
                        Flow.addEdge(e.v,n+e.i,1,0)
                    }
                }
            }
        }
        return Flow.dinic(s,t)
    }
}

fun main(){
    val(n,m,k)=ris()
    val G=Graph(n,m)
    pln(min(k,G.Solve()))
    output()
}