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

fun getid(row : Int): Int{
    val kek = (row - 1)/2;
    return 2 + 3 * kek;
}

fun main(){
    var (a, x, y) = readInts();
    a = a * 2;
    x = x * 2;
    y = y * 2;
    if(y%a == 0){
        println(-1);
        return;
    }
    val row = y/a;
    if(row <= 1){
        if(abs(x) >= a/2){println(-1);}
        else{println(row + 1);}
        return;
    }
    if(row%2 == 0){
        if(x != 0 && abs(x) < a){
            if(x < 0)println(getid(row - 1) + 1);
            else println(getid(row - 1) + 2);
        }
        else{println(-1);}
    }
    else{
        if(abs(x) < a/2){println(getid(row));}
        else{println(-1);}
    }
}