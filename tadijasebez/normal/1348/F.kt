import java.util.*
import java.math.*
import kotlin.math.*

fun readLn()=readLine()!!
fun readInt()=readLn().toInt()
fun readInts()=readLn().split(" ").map{it.toInt()}
fun readLong()=readLn().toLong()
fun readLongs()=readLn().split(" ").map{it.toLong()}

val out=mutableListOf<String>()
fun printLine(s:String){out.add(s)}
fun output(){println(out.joinToString("\n"))}

fun main(){
    val n=readInt()
    val us=Array(n+1){ArrayList<Pair<Int,Int>>()}
    val ans=Array(n){0}
    val l=Array(n){0}
    var r=Array(n){0}
    for(i in 0 until n){
        var (x,y)=readInts()
        l[i]=x
        r[i]=y
        us[l[i]].add(Pair(r[i],i))
    }
    val st=PriorityQueue<Pair<Int,Int>>(compareBy{it.first})
    val R=Array(n+1){0}
    val L=Array(n+1){0}
    val my=Array(n+1){0}
    for(i in 1..n){
        for(j in us[i])st.add(j)
        var x=st.first().first
        ans[st.first().second]=i
        R[i]=r[st.first().second]
        L[i]=l[st.first().second]
        my[i]=st.first().second
        st.remove()
    }
    var a=-1
    var b=-1
    val ord:SortedSet<Int> =TreeSet(compareBy({R[it]},{it}))
    val ids:SortedSet<Int> =TreeSet(compareBy{it})
    for(i in 1..n){
        if(ids.size>0 && ids.last()>=L[i]){
            a=my[i]
            b=my[ids.last()]
        }
        ord.add(i)
        ids.add(i)
        while(ord.size>0 && R[ord.first()]==i){
            ids.remove(ord.first())
            ord.remove(ord.first())
        }
    }
    if(a==-1){
        printLine("YES")
        printLine(ans.joinToString(" "))
    }else{
        printLine("NO")
        printLine(ans.joinToString(" "))
        ans[a]=ans[b].also{ans[b]=ans[a]}
        printLine(ans.joinToString(" "))
    }
    output()
}