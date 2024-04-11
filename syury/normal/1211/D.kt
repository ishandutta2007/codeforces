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
    val (n, a, b, k) = readInts();
    val tmp = readInts();
    var r = tmp.sorted();
    var ans = 0;
    var alive = IntArray(n);
    for(i in 0..n-1){alive[i] = 1;}
    if(a > b){
        var i = 0;
        var j = 0;
        while(i < n){
            var got = 0;
            val x = r[i];
            while(i < n && got < a && r[i] == x){got += alive[i]; ++i;}
            if(got < a){continue;}
            while(j < n && r[j] < x * k){++j;}
            var got2 = 0;
            while(j < n && got2 < b && r[j] == x * k){
                got2 += alive[j];
                ++j;
            }
            if(got2 < b){continue;}
            ++ans;
            var k = i - 1;
            while(got > 0){
                got -= alive[k];
                alive[k] = 0;
                --k;
            }
            k = j - 1;
            while(got2 > 0){
                got2 -= alive[k];
                alive[k] = 0;
                --k;
            }
        }
    }
    else{
        r = r.reversed();
        var i = 0;
        var j = 0;
        while(i < n){
            var got = 0;
            val x = r[i];
            while(i < n && got < b && r[i] == x){got += alive[i]; ++i;}
            if(got < b || x%k != 0){continue;}
            val y = x/k;
            while(j < n && r[j] > y){++j;}
            var got2 = 0;
            while(j < n && got2 < a && r[j] == y){
                got2 += alive[j];
                ++j;
            }
            if(got2 < a){continue;}
            ++ans;
            var k = i - 1;
            while(got > 0){
                got -= alive[k];
                alive[k] = 0;
                --k;
            }
            k = j - 1;
            while(got2 > 0){
                got2 -= alive[k];
                alive[k] = 0;
                --k;
            }
        }
    }
    println(ans);
}