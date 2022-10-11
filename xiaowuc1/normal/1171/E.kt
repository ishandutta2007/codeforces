import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

fun main(args: Array<String>) {
    var l = ArrayList<Char>()
    readLn()
    for(x in readLn()) {
        l.add(x)
    }
    Collections.sort(l)
    if(l.size == 1) {
        println("Yes")
        System.exit(0)
    }
    for(i in 1 until l.size) {
        if(l[i] == l[i-1]) {
            println("Yes")
            System.exit(0)
        }
    }
    println("No")
}