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

inline fun get(cnt: Int, k1: Long, k2: Long): Long{
    if(cnt%2 == 0){
        return min(k1 * cnt.toLong(), k2 * (cnt/2).toLong())
    }
    else{
        if(2*k1 <= k2){
            return k1 * cnt.toLong()
        }
        else{
            return k2 * (cnt/2).toLong() + min(k2, k1)
        }
    }
}

fun main(){
    val T = readInt()
    for(t in 1..T){
        val (n, k1, k2) = readInts()
        val s = readLn()
        var ans = 0L
        var cnt = 0
        for(i in 0..n-1){
            if(s[i] == '1'){
                ++cnt
            }
            else{
                if(cnt != 0){
                    ans += get(cnt, k1.toLong(), k2.toLong())
                }
                cnt = 0
            }
        }
        if(cnt != 0){
            ans += get(cnt, k1.toLong(), k2.toLong())
        }
        println(ans)
    }
}