import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

fun main(args: Array<String>) {
    var l = ArrayList<Int>()
    var m = ArrayList<Int>()
    for(x in readInts()) {
        l.add(x)
    }
    for(x in readInts()) {
        m.add(x)
    }
    if(l[0] > m[0]) {
        println("NO")
        System.exit(0)
    }
    m[0] -= l[0]
    val have = m[0] + m[1]
    if(l[1] > have) {
        println("NO")
        System.exit(0)
    }
    if(l[1] + l[2] > m[0] + m[1] + m[2]) {
        println("NO")
    }
    else {
        println("YES")
    }
}