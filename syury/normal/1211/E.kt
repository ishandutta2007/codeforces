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
    var l = 0;
    var r = n;
    var cnt = IntArray(n+2);
    var p = IntArray(n+2);
    while(r - l > 1){
        val x = (l + r)/2;
        var ok = 1;
        for(i in 1..x){
            cnt[i] = 0;
        }
        for(i in 0..n-1){
            if(a[i] <= x){++cnt[a[i]];}
        }
        for(i in 1..x){
            if(cnt[i] != 2){
                ok = 0;
                break;
            }
            cnt[i] = 0;
        }
        var ptr = 0;
        if(ok == 0){r = x; continue;}
        for(i in 0..n-1){
            if(a[i] > x){continue;}
            val y = a[i];
            if(cnt[y] == 0){
                p[ptr] = i;
                ++ptr;
                ++cnt[y];
            }
        }
        ptr = 0;
        var p2 = 0;
        for(i in 0..n-1){
            if(a[i] > x){continue;}
            if(ptr < x && i == p[ptr]){
                ++ptr;
                continue;
            }
            if(a[p[p2]] != a[i]){ok = 0; break;}
            ++p2;
        }
        if(ok == 1){l = x;}
        else{r = x;}
    }
    val total = l;
    var ptr = 0;
    for(i in 0..n){cnt[i] = 0;}
    for(i in 0..n-1){
        if(a[i] > total){continue;}
        val y = a[i];
        if(cnt[y] == 0){
            p[ptr] = i;
            ++ptr;
            ++cnt[y];
        }
    }
    ptr = 0;
    var s = CharArray(n);
    for(i in 0..n-1){
        if(a[i] > total){s[i] = 'B'; continue;}
        if(ptr < total && i == p[ptr]){
            s[i] = 'R';
            ++ptr;
            continue;
        }
        s[i] = 'G';
    }
    println(s.joinToString(""));
}