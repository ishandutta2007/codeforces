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
    val T = readInt()
    for(t in 1..T){
        val (n, a, b) = readInts()
        var ans = CharArray(n)
        var i = 0
        while(i < n){
            var cnt = a - b + 1
            while(i < n && cnt > 0){
                ans[i] = 'a';
                i++
                cnt--
            }
            if(i == n){break}
            for(j in 1..b-1){
                ans[i] = 'a' + j;
                i++
                if(i == n){break}
            }
        }
        println(ans.joinToString(""))
    }
}