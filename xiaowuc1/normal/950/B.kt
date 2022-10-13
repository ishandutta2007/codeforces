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
    val (n, m) = readInts()
    val a = readInts()
    val b = readInts()
    var ret = 0
    var i = 0
    var j = 0
    var diff = 0
    while(i < a.size && j < b.size) {
        ret++
        diff += a[i++]
        diff -= b[j++]
        while(diff != 0) {
            if(diff < 0) diff += a[i++]
            else diff -= b[j++]
        }
    }
    println(ret)
}