import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.*
val input = BufferedReader(InputStreamReader(System.`in`))
val output = StringBuilder()
fun readln() = input.readLine()
fun readint() = readln().toInt()
fun readlong() = readln().toLong()
fun readstrings() = ArrayList(readln().split(" "))
fun readints() = ArrayList(readstrings().map { it.toInt() })
fun readlongs() = ArrayList(readstrings().map { it.toLong() })
fun cout(s: String) = output.appendln(s)
fun cout(s: Int) = output.appendln(s.toString())
fun cout(s: Long) = output.appendln(s.toString())

fun main() {
    var tt = readint()
    while (tt-- > 0) {
        var n=readint()
        var c=readints()
        var d=readints()
        var g=Array(n){ArrayList<Int>()}
        for(i in 0..n-2){
            var(x,y)=readints()
            x--
            y--
            g[x].add(y)
            g[y].add(x)
        }
        var root=-1
        for(i in 0..n-1){
            if(c[i]!=d[i]){
                root=i
                break
            }
        }
        if(root==-1){
            println("Yes\n0\n")
            continue
        }
        var b=BooleanArray(n)
        var depth=IntArray(n)
        fun dfs(v: Int, p: Int) {
            if(c[v]!=d[v]){
                b[v]=true
            }
            for (to in g[v]) {
                if (to == p) {
                    continue
                }
                depth[to]=depth[v]+1
                dfs(to, v)
                if(b[to]==true){
                    b[v]=true
                }
            }
        }
        dfs(root,-1)
        var mx=-1
        for(i in 0..n-1){
            if(b[i] && (depth[i]>mx)){
                mx=depth[i]
                root=i
            }
        }
        var ok=true
        var a=ArrayList<Int>()
        var p=-1
        var v=root
        a.add(v)
        while(ok && v!=-1){
            var id=-1
            for(to in g[v]){
                if(b[to]&&(p!=to)){
                    if(id!=-1){
                        ok=false
                        break
                    }
                    id=to
                    a.add(to)
                }
            }
            p=v
            v=id
        }
        if(ok==false){
            println("No")
            continue
        }
        for(q in 0..1){
            ok=true
            a.reverse()
            for(i in 1..a.size-1){
                if(c[a[i]]!=d[a[i-1]]){
                    ok=false
                    break
                }
            }
            if(d[a[a.size-1]]!=c[a[0]]){
                ok=false
            }
            if(ok){
                break
            }
        }
        if(ok==false){
            println("No")
            continue
        }
        println("Yes")
        println(a.size)
        for(i in 0..a.size-1){
            a[i]++
        }
        println(a.joinToString(" "))
    }
    print(output)
}