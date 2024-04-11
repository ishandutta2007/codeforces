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
    val (n, m) = readInts();
    var gr = ArrayList<ArrayList<Int> > ();
    var ptr = IntArray(n);
    var ans = ArrayList<ArrayList<Int> > ();
    var ea = BooleanArray(m);
    var fst = IntArray(m);
    var snd = IntArray(m);
    var stk = IntArray(m + 14);
    var seq = IntArray(2*n + m + 14);
    var was = BooleanArray(n);
    var sp = 0;
    var seqp = 0;
    for(i in 0..n-1){
        was[i] = false;
        ptr[i] = 0;
        gr.add(ArrayList<Int>());
    }
    for(i in 0..m-1){
        ea[i] = true;
        var (v, u) = readInts();
        --v; --u;
        fst[i] = v;
        snd[i] = u;
        gr[v].add(i);
        gr[u].add(i);
    }
    fun other(i : Int, v : Int) : Int{
        if(v == fst[i]){return snd[i];}
        else{return fst[i];}
    }
    for(i in 0..n-1){
        if(gr[i].size%2 == 1){
            println("NO");
            exit();
        }
    }
    println("YES");
    var euler_ptr = 0;
    while(euler_ptr < n){
        if(ptr[euler_ptr] == gr[euler_ptr].size){++euler_ptr; continue;}
        seqp = 0;
        stk[sp] = euler_ptr;
        ++sp;
        while(sp > 0){
            val v = stk[sp - 1];
            seq[seqp] = v;
            was[v] = true;
            ++seqp;
            while(ptr[v] < gr[v].size && !ea[gr[v][ptr[v]]]){++ptr[v];}
            if(ptr[v] < gr[v].size){
                ea[gr[v][ptr[v]]] = false;
                val u = other(gr[v][ptr[v]], v);
                ++ptr[v];
                stk[sp] = u;
                ++sp;
                if(was[u]){
                    var cu : Int;
                    var id = ans.size;
                    ans.add(ArrayList<Int>());
                    ans[id].add(u + 1);
                    do{
                        cu = seq[seqp - 1];
                        ans[id].add(cu + 1);
                        was[cu] = false;
                        --seqp;
                    }while(cu != u);
                }
            }
            else{--sp;}
        }
        ++euler_ptr;
    }
    println(ans.size);
    for(i in 0..ans.size-1){
        print(ans[i].size); print(' ');
        println(ans[i].joinToString(" "));
    }
}