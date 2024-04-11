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


fun main(){
    var n = readInt()
    var ans = IntArray(n);
    var seq = IntArray(n);
    for(i in 1..n){
        seq[i - 1] = i;
    }
    var mul = 1;
    var ptr = 0;
    while(n > 0){
        if(n == 1){
            ans[ptr++] = mul;
            break;
        }
        if(n == 2){
            ans[ptr++] = mul;
            ans[ptr++] = mul * 2;
            break;
        }
        if(n == 3){
            ans[ptr++] = mul;
            ans[ptr++] = mul;
            ans[ptr++] = mul * 3;
            break;
        }
        for(i in 0..n-1){
            if(seq[i]%2 == 1){ans[ptr++] = mul;}
        }
        for(i in 0..n/2-1){
            seq[i] = seq[2*i + 1]/2;
        }
        n /= 2;
        mul *= 2;
    }
    println(ans.joinToString(" "));
}