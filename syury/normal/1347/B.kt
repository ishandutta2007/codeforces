import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

inline fun <T : Comparable<T> > min(x : T, y : T): T{
    if(x < y){return x;}
    else{return y;}
}

inline fun <T : Comparable<T> > max(x : T, y : T): T{
    if(x > y){return x;}
    else{return y;}
}

fun main(){
    val T = readInt()
    for(t in 1..T){
        var (a1, b1) = readInts()
        var (a2, b2) = readInts()
        if(a1 > b1){
            a1 = b1.also {b1 = a1}
        }
        if(a2 > b2){
            a2 = b2.also {b2 = a2}
        }
        if((a1 + a2 == b1) and (b1 == b2)){
            println("Yes");
            continue;
        }
        println("No")
    }
}