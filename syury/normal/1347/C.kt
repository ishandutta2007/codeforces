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
        val s = readStrings()[0]
        val n = s.length
        var a = ArrayList<Int>()
        var mul = 1
        for(i in n-1 downTo 0){
            val curr = mul * (s[i].toInt() - 48)
            if(curr != 0){
                a.add(curr)
            }
            mul *= 10
        }
        println(a.size)
        println(a.joinToString(" "))
    }
}