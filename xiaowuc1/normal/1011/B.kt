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
    val (k, n) = readInts()
    val l = IntArray(101)
    for(x in readInts()) {
        l[x]++
    }
    var lhs = 0
    var rhs = 10000
    while(lhs != rhs) {
        val mid = (lhs + rhs + 1) / 2
        var can = 0
        for(x in l) {
            can += x / mid
        }
        if(can >= k) lhs = mid
        else rhs = mid - 1
    }
    println(lhs)
}

/*
useful things:
to read in multiple ints in one line
val (n, m, k) = readInts()

Java: int[] dx = new int[]{-1,1,0,0}
Kotlin: val dx = arrayOf(-1, 1, 0, 0)
*/