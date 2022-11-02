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

fun fail(){
    println("NO");
    exit();
}

fun main(){
    var lol = readInts();
    var x = lol[0];
    var y = lol[1];
    var z = lol[2];
    lol = readInts();
    var a = lol[0];
    var b = lol[1];
     var c = lol[2];
    if(x > a){fail();}
    a -= x;
    if(y > a + b){fail();}
    var kek = min<Int>(a, y);
    y -= kek;
    a -= kek;
    kek = min<Int>(b, y);
    b -= kek;
    y -= kek;
    if(z > a + b + c){fail();}
    println("YES");
}