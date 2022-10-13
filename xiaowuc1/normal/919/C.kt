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
    val (n, m, k) = readInts()
    val l = ArrayList<String>()
    repeat(n) {
        l.add(readLn())
    }
    var ret = 0
    for(i in 0 until n) {
        var curr = 0
        for(j in 0 until m) {
            if(l[i][j] == '*') curr = 0
            else curr++
            if(curr >= k) ret++
        }
    }
    if(k > 1) {
        for(i in 0 until m) {
            var curr = 0
            for (j in 0 until n) {
                if (l[j][i] == '*') curr = 0
                else curr++
                if (curr >= k) ret++
            }
        }
    }
    println(ret)
}

/*
useful things:
to read in multiple ints in one line
val (n, m, k) = readInts()

Java: int[] dx = new int[]{-1,1,0,0}
Kotlin: val dx = arrayOf(-1, 1, 0, 0)
*/