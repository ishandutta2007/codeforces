import java.util.*
import kotlin.system.exitProcess
import kotlin.math.*

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

fun main(){
    val N = 200006;
    val T = readInt();
    var must = IntArray(N);
    var p = IntArray(N);
    var depth = IntArray(N);
    var q = IntArray(N);
    var has = IntArray(N);
    var qh = 0;
    var qt = 0;
    for(test in 0..T-1){
        val n = readInt();
        val c = readInts();
        val d = readInts();
        var gr = ArrayList<ArrayList<Int> >();
        var pidor = ArrayList<Int>();
        for(i in 0..n-1){
            has[i] = 0;
            p[i] = 0;
            must[i] = 0;
            depth[i] = -1;
            if(c[i] != d[i]){must[i] = 1;}
            gr.add(ArrayList<Int>());
        }
        p[0] = -1;
        qh = 0; qt = 0;
        for(i in 1..n-1){
            var (v, u) = readInts();
            --u; --v;
            gr[v].add(u);
            gr[u].add(v);
        }
        depth[0] = 0;
        q[qt++] = 0;
        while(qh < qt){
            val v = q[qh++];
            for(u in gr[v]){
                if(depth[u] == -1){
                    q[qt++] = u;
                    depth[u] = depth[v] + 1;
                    p[u] = v;
                }
            }
        }
        var root = -1;
        for(i in 0..n-1){
            if(must[i] == 1 && (root == -1 || depth[root] < depth[i])){root = i;}
        }
        if(root == -1){
            println("Yes");
            println(0);
            continue;
        }
        qh = 0; qt = 0;
        for(i in 0..n-1){
            p[i] = -1;
            depth[i] = -1;
        }
        depth[root] = 0;
        q[qt++] = root;
        while(qh < qt){
            val v = q[qh++];
            pidor.add(v);
            for(u in gr[v]){
                if(depth[u] == -1){
                    depth[u] = depth[v] + 1;
                    p[u] = v;
                    q[qt++] = u;
                }
            }
        }
        var dor = pidor.reversed();
        for(v in dor){
            if(must[v] == 1){has[v] = 1;}
            if(p[v] != -1 && has[v] == 1){has[p[v]] = 1;}
        }
        var v = root;
        var ok = 1;
        var seq = ArrayList<Int>();
        while(true){
            seq.add(v);
            var nxt = -1;
            for(u in gr[v]){
                if(u == p[v]){continue;}
                if(has[u] == 1){
                    if(nxt != -1){ok = 0;}
                    nxt = u;
                }
            }
            if(ok == 0 || nxt == -1){break;}
            v = nxt;
        }
        for(v in seq){must[v] = 0;}
        for(i in 0..n-1){if(must[v] == 1){ok = 0;}}
        if(ok == 0){
            println("No");
            continue;
        }
        ok = 1;
        var prv : Int;
        prv = c[seq.last()];
        for(v in seq){
            if(prv != d[v]){ok = 0; break;}
            prv = c[v];
        }
        if(ok == 1){
            println("Yes");
            println(seq.size);
            println((seq.reversed().map { it + 1 }).joinToString(" "));
            continue;
        }
        ok = 1;
        var sseq = seq.reversed();
        prv = c[sseq.last()];
        for(v in sseq){
            if(prv != d[v]){ok = 0; break;}
            prv = c[v];
        }
        if(ok == 1){
            println("Yes");
            println(sseq.size);
            println((sseq.reversed().map { it + 1 }).joinToString(" "));
            continue;
        }
        println("No");
    }
}