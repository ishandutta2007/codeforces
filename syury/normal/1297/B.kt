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
    val t = readInt()
    for(testid in 0..t-1){
        val n = readInt()
        var a = IntArray(n)
        var b = IntArray(n)
        for(i in 0..n-1){
            val (x, y) = readInts()
            a[i] = x;
            b[i] = y;
        }
        var ans = -1
        for(i in 0..n-1){
            var x = a[i]
            var tot = 0
            for(j in 0..n-1){
                if((x >= a[j]) && (b[j] >= x)){++tot;}
            }
            if(tot == 1){ans = x; break;}
            x = b[i] + 1
            tot = 0
            for(j in 0..n-1){
                if((x >= a[j]) && (b[j] >= x)){++tot;}
            }
            if(tot == 1){ans = x; break;}
        }
        println(ans)
    }
}