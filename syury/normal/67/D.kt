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
    
    fun upd(pos : Int, v : Int){
        var idx = pos;
        while(idx <= n){
            t[idx] = max(t[idx], v);
            idx += idx and (-idx);
        }
    }
    
    fun pref(pos : Int): Int{
        var ans = 0;
        var idx = pos;
        while(idx != 0){
            ans = max(ans, t[idx]);
            idx -= idx and (-idx);
        }
        return ans;
    }
}

fun main(){
    var n = readInt();
    var a = readInts();
    var b = readInts().toIntArray();
    var pos = IntArray(1+n);
    b.reverse();
    for(i in 0..n-1){
        pos[a[i]] = i;
    }
    for(i in 0..n-1){
        b[i] = pos[b[i]];
    }
    var t = Fenwick(n);
    var ans = 0;
    for(i in 0..n-1){
        var curr = t.pref(b[i]);
        ans = max(ans, curr + 1);
        t.upd(b[i] + 1, curr + 1);
    }
    println(ans);
}