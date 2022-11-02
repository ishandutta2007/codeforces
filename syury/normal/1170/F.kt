import java.util.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun exit() : Nothing = exitProcess(0)

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}

class Fenwick(val n : Int){
    var t = IntArray(n + 1);
    
    fun inc(pos : Int){
        var idx = pos;
        while(idx <= n){
            ++t[idx];
            idx += idx and (-idx);
        }
    }
    
    fun pref(pos : Int): Int{
        var ans = 0;
        var idx = pos;
        while(idx != 0){
            ans += t[idx];
            idx -= idx and (-idx);
        }
        return ans;
    }
}

fun main(){
    val (n, m, k) = readInts();
    val a = readLongs().sorted();
    var pref = LongArray(n);
    for(i in 0..n-1){
        pref[i] = a[i];
        if(i != 0){pref[i] += pref[i - 1];}
    }
    fun getsum(l : Int, r : Int) : Long{
        if(l > r){return 0;}
        if(l == 0){return pref[r];}
        else{return pref[r] - pref[l - 1];}
    }
    var sum : Long;
    var ans : Long;
    ans = 1;
    for(i in 1..18){
        ans *= 10;
    }
    sum = 0;
    var ptr = 0;
    var i = 0;
    while(i + m <= n){
        while(ptr < i + m && a[ptr] * (ptr - i) - sum <= k){sum += a[ptr]; ++ptr;}
        var pos = min(ptr - 1, i + m/2);
        var x = a[pos];
        if(pos < i + m/2){
            var can_inc = a[pos] * (pos - i) - getsum(i, pos - 1);
            can_inc = (k - can_inc)/(pos - i + 1);
            x += can_inc;
        }
        var curr : Long;
        curr = 0;
        curr += x * (pos - i + 1) - getsum(i, pos);
        curr += -x * (i + m - 1 - pos) + getsum(pos + 1, i + m - 1);
        ans = min(ans, curr);
        sum -= a[i];
        ++i;
    }
    println(ans);
}