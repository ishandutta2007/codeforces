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
    val t = readInt()
    for(i in 0..t-1){
        val n = readInt()
        if(n < 1000){
            println(n)
        }
        else if(n < 1000000){
            var cnt = n/1000;
            if((cnt + 1)*1000 - n <= n - cnt*1000){++cnt;}
            if(cnt == 1000){
                println("1M")
            }
            else{
                println(cnt.toString() + "K")
            }
        }
        else{
            var cnt = n/1000000;
            if((cnt + 1)*1000000 - n <= n - cnt*1000000){++cnt;}
            println(cnt.toString() + "M")
        }
    }
}