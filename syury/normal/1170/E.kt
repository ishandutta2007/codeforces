import java.util.*
import kotlin.system.exitProcess

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
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
    val (n, m) = readInts();
    val a = readInts();
    var pref = IntArray(n);
    for(i in 0..n-1){
        pref[i] = a[i];
        if(i != 0){pref[i] += pref[i - 1];}
    }
    var q = readInt();
    while(q != 0){
        --q;
        val c = readInts();
        var prv = 0;
        var j = 0;
        val sz = c[0];
        var P = 0;
        for(i in 1..sz){
            val x = c[i];
            val len = x - 1 - prv;
            var L = 0;
            var R = n - j + 1;
            while(R - L > 1){
                val mid = (L + R)/2;
                val clen = pref[j - 1 + mid] - P;
                if(clen <= len){L = mid;}
                else{R = mid;}
            }
            j += L;
            if(j != 0){P = pref[j - 1];}
            prv = x;
        }
        val len = m - prv;
        var L = 0;
        var R = n - j + 1;
        while(R - L > 1){
            val mid = (L + R)/2;
            val clen = pref[j - 1 + mid] - P;
            if(clen <= len){L = mid;}
            else{R = mid;}
        }
        j += L;
        if(j == n){println("YES");}else{println("NO");}
    }
}