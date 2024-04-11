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
    if(readInt() == 2) println(2)
    else println(1)
}

/*
useful things:
to read in multiple ints in one line
val (n, m, k) = readInts()

Java: int[] dx = new int[]{-1,1,0,0}
Kotlin: val dx = arrayOf(-1, 1, 0, 0)
*/