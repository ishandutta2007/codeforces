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

fun main(){
    val T = 1//readInt()
    for(t in 1..T){
        val (n, m, d) = readInts()
        val a = readInts()
        var i = 0
        var x = d
        var bg = IntArray(m)
        while(i < m){
            if(x + a[i] - 1 > n){break}
            bg[i] = x
            x = x + a[i] + d - 1
            ++i
        }
        if(i == m && x < n + 1){
            println("NO")
            return
        }
        var sum = 0
        println("YES")
        for(j in m-1 downTo i){
            sum += a[j]
            bg[j] = n - sum + 1
        }
        if(i != m){
            var fin = 0
            if(i != 0){fin = bg[i - 1] + a[i - 1]}
            //println(fin)
            var mv = fin - bg[i]
            for(j in i-1 downTo 0){
                if(mv <= 0){break}
                bg[j] -= mv
                mv -= d - 1
            }
        }
        var ans = IntArray(n)
        for(i in 0..m-1){
            for(j in 0..a[i]-1){
                ans[bg[i] + j - 1] = i + 1
            }
        }
        println(ans.joinToString(" "))
    }
}