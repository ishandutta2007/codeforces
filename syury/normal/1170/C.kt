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
    var T = readInt();
    while(T != 0){
        --T;
        val s = readLn();
        val t = readLn();
        val n = s.length;
        val m = t.length;
        var i = 0;
        var j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){++i; ++j; continue;}
            if(s[i] == '+'){break;}
            if(i + 1 == n || s[i + 1] == '+'){break;}
            i += 2;
            ++j;
        }
        if(i != n || j != m){println("NO");}else{println("YES");}
    }
}