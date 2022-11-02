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

data class Day (val a: Int, val b: Int, val c: Int){}

class CompareDays{
    companion object : Comparator<Day> {
        override fun compare(a: Day, b: Day): Int = when {
            a.c < b.c -> -1
            a.c > b.c -> 1
            else -> 0
        }
    }
}

fun main(){
    var (n, k) = readInts();
    var d = ArrayList<Day>();
    for(i in 0..n-1){
        val (a, b, c) = readInts();
        d.add(Day(a, b, c));
    }
    var p = d.sortedWith(CompareDays);
    for(i in 0..n-1){
        k = k - p[i].a;
        if(k < 0){
            println(-1);
            return;
        }
    }
    var ans : Long;
    ans = 0;
    for(i in 0..n-1){
        ans = ans + p[i].c.toLong() * p[i].a.toLong();
        var cu = min(k, p[i].b - p[i].a);
        ans = ans + p[i].c.toLong() * cu.toLong();
        k = k - cu;
    }
    if(k > 0){
        println(-1);
        return;
    }
    println(ans);
}