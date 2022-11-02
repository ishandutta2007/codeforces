import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}

inline fun div(s: Long, n: Int): Long{
    val k = n.toLong()
    if(s%k == 0L){return s/k;}
    else{return s/k + 1L;}
}

fun main(){
    val T = readInt()
    for(t in 1..T){
        val (n, m) = readInts()
        var ans = ArrayList<Int>(n)
        var vs = ArrayList<Int>(m)
        var us = ArrayList<Int>(m)
        var ws = ArrayList<Int>(m)
        var eds = ArrayList<Long>(m)
        for(i in 1..n){
            ans.add(0)
        }
        for(i in 0..m-1){
            var (v, u, w) = readInts()
            --v; --u;
            vs.add(v)
            us.add(u)
            ws.add(w)
            eds.add(w.toLong() * m.toLong() + i)
        }
        var s = eds.sorted()
        for(i in m-1 downTo 0){
            var evt = s.get(i)
            val w = (evt/m.toLong()).toInt()
            val idx = (evt%m.toLong()).toInt()
            val v = vs.get(idx)
            val u = us.get(idx)
            ans[u] = max(ans[u], w)
            ans[v] = max(ans[v], w)
        }
        var ok = 1
        for(i in 0..m-1){
            val cw = min(ans.get(vs.get(i)), ans.get(us.get(i)))
            if(cw != ws.get(i)){ok = 0; break}
        }
        if(ok == 1){
            println("YES")
            println(ans.joinToString(" "))
        }
        else{
            println("NO")
        }
    }
}