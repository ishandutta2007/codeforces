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
    //val T = readInt()
    //for(t in 1..T){
        var (n, m, k) = readInts()
        var ans = ArrayList<Int>(n)
        --k;
        for(i in 0..n-1){
            if(k == i){
                ans.add(0)
            }
            else{
                ans.add(m + 1)
            }
        }
        for(i in 0..m-1){
            var (v, u) = readInts()
            --v; --u;
            val oldv = ans.get(v)
            val oldu = ans.get(u)
            ans[v] = min(oldv + 1, oldu)
            ans[u] = min(oldu + 1, oldv)
        }
        for(i in 0..n-1){
            if(ans.get(i) >= m + 1){ans[i] = -1}
        }
        println(ans.joinToString(" "))
    //}
}