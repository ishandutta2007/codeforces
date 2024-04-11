import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readDouble() = readLn().toDouble() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readDoubles() = readStrings().map { it.toDouble() } // list of ints

fun main(args: Array<String>) {
    val t = readInt()
    repeat(t) {
        solve()
    }
}

fun solve() {
    val n = readInt()
    var l = ArrayList<State>()
    repeat(n) { i: Int ->
        val ll = readInts()
        l.add(State(ll[0], ll[1], i))
    }
    Collections.sort(l, Comparator { e1, e2 -> e1.l - e2.l })
    var ret = IntArray(n)
    var smallest = IntArray(n)
    for(i in 0 until n) ret[i] = 1
    var max = 0
    var good = false
    for(i in 0 until n-1) {
        ret[l[i].i] = 2
        max = Math.max(max, l[i].r)
        if(max < l[i+1].l) {
            good = true
            break
        }
    }
    if(!good) println(-1)
    else println(ret.joinToString(" "))
}

class State(val l: Int, val r: Int, val i: Int)