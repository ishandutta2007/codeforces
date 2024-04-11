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
    var tt = readint()
    while (tt-- > 0) {
        var(n,m)=readints()
        var u=IntArray(m)
        var v=IntArray(m)
        var w=IntArray(m)
        var ans=IntArray(n)
        for(i in 0..m-1){
            var(a,b,c)=readints()
            u[i]=a
            v[i]=b
            w[i]=c
            u[i]--
            v[i]--
            ans[u[i]]=maxOf(ans[u[i]],c)
            ans[v[i]]=maxOf(ans[v[i]],c)
        }
        var ok=true
        for(i in 0..m-1){
            if(minOf(ans[u[i]],ans[v[i]])!=w[i]){
                ok=false
                break
            }
        }
        if(ok){
            println("YES")
            println(ans.joinToString(" "))
        }else{
            println("NO")
        }

    }
}