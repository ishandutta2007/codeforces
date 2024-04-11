import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

fun main(args: Array<String>) {
    solve()
    /*
    val t = readInt()
    repeat(t) {
        solve()
    }
    */
}

fun solve() {
    val n = readInt()
    val a = readInts()
    val b = readInts()
    Collections.sort(a)
    Collections.sort(b)
    var ret = 0L
    var i = n-1
    var j = n-1
    while(i >= 0 || j >= 0) {
        if(i < 0 || (j >= 0 && b[j] > a[i])) j--
        else ret += a[i--]
        if(j < 0 || (i >= 0 && a[i] > b[j])) i--
        else ret -= b[j--]
    }
    println(ret)
}

/*
useful things:
Java: int[] dx = new int[]{-1,1,0,0}
Kotlin: val dx = arrayOf(-1, 1, 0, 0)
*/