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
        val a = readInts()
        var l = 0
        var r = n - 1
        var turn = 0
        var A = 0
        var B = 0
        var total = 0
        var prv = 0
        while(l <= r){
            ++total
            if(turn == 0){
                var curr = 0
                while((l <= r) and (curr <= prv)){
                    curr += a[l++]
                }
                A += curr
                prv = curr
            }
            else{
                var curr = 0
                while((l <= r) and (curr <= prv)){
                    curr += a[r--]
                }
                B += curr
                prv = curr
            }
            turn = 1 - turn
        }
        print(total)
        print(' ')
        print(A)
        print(' ')
        println(B)
    }
}