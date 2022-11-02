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

data class Edge(val to: Int, val id: Int){}

fun main(){
    val n = readInt();
    val kot = "kotlin";
    var gr = ArrayList<ArrayList<Edge> >();
    var ptr = IntArray(6);
    for(i in 0..5){
        ptr[i] = 0;
        gr.add(ArrayList<Edge>());
    }
    for(i in 0..n-1){
        val s = readLn();
        val c = s.first();
        val d = s.last();
        var sta = -1;
        var fin = -1;
        for(j in 0..5){
            if(kot[j] == c){
                sta = j;
            }
            if(kot[j] == d){
                fin = j + 1;
                if(fin == 6){fin = 0;}
            }
        }
        gr[sta].add(Edge(fin, i + 1));
    }
    var stk = IntArray(2 * n + 100);
    var inside = IntArray(2 * n + 100);
    var sp = 0;
    stk[sp++] = 0;
    var ans = ArrayList<Int>();
    while(sp > 0){
        val v = stk[sp - 1];
        if(ptr[v] < gr[v].size){
            inside[sp] = gr[v][ptr[v]].id;
            stk[sp] = gr[v][ptr[v]].to;
            ++sp;
            ++ptr[v];
        }
        else{
            if(sp - 1 > 0)ans.add(inside[sp - 1]);
            --sp;
        }
    }
    println(ans.reversed().joinToString(" "));
}