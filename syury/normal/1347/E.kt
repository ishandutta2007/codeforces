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
        val n = readInt()
        if(n <= 3){
            println(-1)
            continue
        }
        var a = ArrayList<Int>()
        if(n%2 == 1){
            for(i in 1 until n-4 step 2){
                a.add(i)
            }
            a.add(n - 3)
            a.add(n - 1)
            a.add(n - 4)
            a.add(n)
            a.add(n - 2)
            for(i in n-5 downTo 2 step 2){
                a.add(i)
            }
        }
        else{
            for(i in 1 until n-3 step 2){
                a.add(i)
            }
            a.add(n - 1)
            a.add(n - 3)
            a.add(n)
            a.add(n - 2)
            for(i in n-4 downTo 2 step 2){
                a.add(i)
            }
        }
        println(a.joinToString(" "))
    }
}