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
    var n = readInt();
    var a = readInts();
    var b = a.sorted().distinct();
    var t = Fenwick(n + 2);
    var ans = 0;
    for(i in 0..n-1){
        var x = b.binarySearch(a[i]);
        x = x + 1;
        var curr = t.pref(x);
        curr = i - curr;
        if(curr >= 2){++ans;}
        t.inc(x);
    }
    println(ans);
}