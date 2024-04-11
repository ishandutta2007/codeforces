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
    val n = readInt();
    val a = readInts();
    var mx = -1;
    var p = -1;
    for(i in 0..n-1){
        if(a[i] >= mx){
            mx = a[i];
            p = i;
        }
    }
    var ans : Long;
    ans = n.toLong();
    ans = ans * (mx - 1);
    ans = ans + p + 1;
    println(ans);
}