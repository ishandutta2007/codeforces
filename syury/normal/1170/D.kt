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
    val m = readInt();
    val a = readInts();
    var n = 0;
    for(j in 0..m-1){
        if(a[j] == -1){++n;}
    }
    var ans = ArrayList<ArrayList<Int> >();
    var i = 0;
    var t = TreeSet<Int>();
    for(j in 0..n-1){t.add(j); ans.add(ArrayList<Int>());}
    while(i < m){
        val alive = ArrayList<Int>(t);
        for(v in alive){
            val x = a[i];
            ++i;
            if(x == -1){t.remove(v);}
            else{ans[v].add(x);}
        }
    }
    println(n);
    for(j in 0..n-1){
        val s = ans[j].size.toString() + " " + ans[j].joinToString(" ");
        println(s);
    }
}