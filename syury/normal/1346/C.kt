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
        val (n, k, x, y) = readInts()
        var a = readInts().sorted()
        var best = 10000000000L
        var sum = 0L
        for(i in 0..n-1){sum += a[i].toLong()}
        if(div(sum, n) <= k){best = y.toLong();}
        var carry = y.toLong()
        for(i in n-1 downTo 0){
            if(a[i] <= k){
                best = min(best, carry - y.toLong())
            }
            carry += x.toLong()
            sum -= a[i].toLong()
            if(div(sum, n) <= k){best = min(best, carry)}
        }
        best = min(best, x.toLong() * n.toLong())
        println(best)
    }
}