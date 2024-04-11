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

fun main(){
    val n = readInt();
    val s = readLn();
    var a = IntArray(27);
    for(i in 0..26){a[i] = 0;}
    var ok = 0;
    for(i in 0..n-1){
        ++a[s[i] - 'a'];
        if(a[s[i] - 'a'] > 1){ok = 1;}
    }
    if(ok == 1 || n == 1){println("Yes");}
    else{println("No");}
}