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
    val g = arrayOf(readLn(), readLn(), readLn(), readLn())
    val dx = arrayOf(-1, -1, -1, 0, 0, 1, 1, 1)
    val dy = arrayOf(-1, 0, 1, -1, 1, -1, 0, 1)
    for(i in 0 until 4) {
        for(j in 0 until 4) {
            for(k in 0 until dx.size) {
                var good = 0
                var valid = true
                for(l in 0 until 3) {
                    var nx = i + dx[k] * l
                    var ny = j + dy[k] * l
                    if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || g[nx][ny] == 'o') valid = false
                    if(valid && g[nx][ny] == 'x') good++
                }
                if(good == 2 && valid) {
                    println("YES")
                    System.exit(0);
                }
            }
        }
    }
    println("NO")
}

/*
useful things:
Java: int[] dx = new int[]{-1,1,0,0}
Kotlin: val dx = arrayOf(-1, 1, 0, 0)
*/