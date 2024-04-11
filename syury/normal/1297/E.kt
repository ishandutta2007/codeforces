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

class P(val x: Int, val y: Int)

fun main(){
    val t = readInt()
    for(testid in 0..t-1){
        val (n, k) = readInts();
        var gr = ArrayList<ArrayList<Int> >();
        for(i in 0..n-1){
            gr.add(ArrayList<Int>());
        }
        for(i in 1..n-1){
            var (v, u) = readInts();
            --v; --u;
            gr[v].add(u);
            gr[u].add(v);
        }
        if(k == 1){
            println("Yes");
            println(1);
            println(1);
            continue;
        }
        var leaves = ArrayList<Int>();
        for(i in 0..n-1){
            if(gr[i].size == 1){
                leaves.add(i);
            }
        }
        if(leaves.size < k){
            println("No");
            continue;
        }
        val root = leaves.get(0);
        var p = IntArray(n);
        p[root] = -1;
        var q = IntArray(n);
        var qh = 0;
        var qt = 0;
        q[qt++] = root;
        while(qh < qt){
            val v = q[qh++];
            for(u in gr[v]){
                if(u != p[v]){
                    p[u] = v;
                    q[qt++] = u;
                }
            }
        }
        var isin = IntArray(n);
        for(i in 0..n-1){isin[i] = 0;}
        for(i in 0..k-1){
            var v = leaves[i];
            while(v != -1 && 0 == isin[v]){
                isin[v] = 1;
                v = p[v];
            }
        }
        var ans = ArrayList<Int>();
        for(i in 0..n-1){
            if(isin[i] == 1){
                ans.add(i + 1);
            }
        }
        println("Yes");
        println(ans.size);
        println(ans.joinToString(" "));
    }
}