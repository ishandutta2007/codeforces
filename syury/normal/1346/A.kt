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
        val (n, k) = readLongs()
        var coeff = 1L
        var sum = 0L
        for(i in 0..3){
            sum += coeff
            coeff *= k
        }
        val lol = n/sum
        print(lol)
        print(' ')
        print(lol * k)
        print(' ')
        print(lol * k * k)
        print(' ')
        println(lol * k * k * k)
    }
}