import java.util.*
import kotlin.math.*

fun readln() = readLine()!!
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readdouble() = readln().toDouble()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun readdoubles() = ArrayList(readstrings().map { it.toDouble() })

fun main() {
    var (n,m,k)=readints()
    var g=Array(n){ArrayList<Int>()}
    var z=IntArray(m)
    var e=Array<Pair<Int,Int>>(m,{Pair(0,0)})
    var w=IntArray(m)
    for(i in 0..m-1){
        var(x,y,ww)=readints()
        x--
        y--
        z[i]=x+y
        w[i]=ww
        e[i]=Pair(x,y)
        g[x].add(i)
        g[y].add(i)
    }
    var d=Array(n){IntArray(n,{1e9.toInt()})}
    for(i in 0..n-1){
        var st=TreeSet<Pair<Int,Int>>(compareBy({it.first},{it.second}))
        d[i][i]=0
        st.add(Pair(0,i))
        while(!st.isEmpty()){
            var p=st.first()
            st.remove(st.first())
            if(d[i][p.second]!=p.first){
                continue
            }
            for(id in g[p.second]){
                var to=z[id]-p.second
                if(d[i][to]>d[i][p.second]+w[id]){
                    d[i][to]=d[i][p.second]+w[id]
                    st.add(Pair(d[i][to],to))
                }
            }
        }
    }
    var ans=1e9.toInt()
    var a=IntArray(k)
    var b=IntArray(k)
    for(i in 0..k-1){
        var(x,y)=readints()
        x--
        y--
        a[i]=x
        b[i]=y
    }
    for(i in 0..m-1){
        var sum=0
        var x=e[i].first
        var y=e[i].second
        for(j in 0..k-1){
            sum+=minOf(d[a[j]][b[j]], d[a[j]][x]+d[y][b[j]], d[a[j]][y]+d[x][b[j]])
        }
        ans=minOf(ans,sum)
    }
    println("$ans")
}