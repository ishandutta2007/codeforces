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
    readLn()
    val s = readLn()
    var l = 0
    var d = 0
    var u = 0
    var r = 0
    for(x in s) {
        if(x == 'L') l++
        if(x == 'R') r++
        if(x == 'D') d++
        if(x == 'U') u++
    }
    println(2*(Math.min(l,r) + Math.min(d,u)))
}

/*
useful things:
to read in multiple ints in one line
val (n, m, k) = readInts()

Java: int[] dx = new int[]{-1,1,0,0}
Kotlin: val dx = arrayOf(-1, 1, 0, 0)
*/