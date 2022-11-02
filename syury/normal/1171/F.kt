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

open class Segment(val l_: Int, val r_: Int, val id_: Int){
    val l = l_;
    val r = r_;
    val id = id_;
    
}

fun main(){
    var T = readInt();
    while(T != 0){
        --T;
        val n = readInt();
        var a = ArrayList<Segment>();
        var ans = IntArray(n);
        for(i in 0..n-1){
            var (l, r) = readInts();
            a.add(Segment(l, r, i));
        }
        val b = a.sortedBy{seg -> seg.l};
        var R = b[0].r;
        var ok = 0;
        for(i in 0..n-1){
            if(R < b[i].l){
                ok = 1;
                for(j in i..n-1){ans[b[j].id] = 2;}
                break;
            }
            R = max(R, b[i].r);
            ans[b[i].id] = 1;
        }
        if(ok == 0){println(-1);}
        else{println(ans.joinToString(" "));}
    }
}