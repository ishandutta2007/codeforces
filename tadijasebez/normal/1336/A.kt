import java.util.*
import java.math.*
 
fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{it.toInt()}
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{it.toLong()}
 
val out = mutableListOf<String>()
fun printLine(s: String) { out.add(s) }
fun output() { println(out.joinToString("\n")) }
 
fun main(){
    var (n, k) = readInts()
    var E = Array(n+1){ArrayList<Int>()}
    for(i in 1 until n){
        var (u, v) = readInts()
        E[u].add(v)
        E[v].add(u)
    }
    var dep = IntArray(n+1){0}
    var sz = IntArray(n+1){0}
    var can = ArrayList<Int>()
    fun DFS(u:Int, p:Int){
        dep[u] = dep[p]+1
        sz[u] = 1
        for(v in E[u]){
            if(v!=p){
                DFS(v,u)
                sz[u]+=sz[v]
            }
        }
        can.add(dep[u]-sz[u])
    }
    DFS(1,0)
    can.sort()
    var ans = 0.toLong()
    for(i in 0 until k){
        ans += can[n-i-1]
    }
    printLine(ans.toString())
    output()
}