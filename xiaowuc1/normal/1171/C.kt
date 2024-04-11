import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

fun main(args: Array<String>) {
    val qq = readInt()
    for(casenum in 0 until qq) {
        val s = readLn()
        val l = ArrayList<Char>()
        for(i in 0 until s.length) {
            l.add(s[i])
        }
        Collections.sort(l)
        if(l[0] == l[l.size-1]) {
            println(-1)
        }
        else {
            for(x in l) {
                print(x)
            }
            println()
        }
    }
}