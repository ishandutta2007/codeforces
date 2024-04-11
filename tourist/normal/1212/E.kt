import java.util.*
import kotlin.Comparator
import kotlin.collections.ArrayList

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    class Event(var cnt: Int, var cost: Int, var id: Int) {}

    var e = ArrayList<Event>()
    var n = readInt()
    for (i in 0..n - 1) {
        var (c, p) = readInts()
        e.add(Event(c, p, i))
    }
    var m = readInt()
    var x = readInts()
    for (i in 0..m - 1) {
        e.add(Event(x[i] + 1, -1, -i - 1))
    }
    e.sortWith(compareBy({ it.cnt }, { it.cost }))
    var s = TreeSet<Pair<Int, Int>>(compareBy<Pair<Int, Int>>({ it.first }, { it.second }))
    var res = ArrayList<Pair<Int, Int>>()
    var ans = 0L
    for (ev in e) {
        if (ev.cost == -1) {
            if (s.isEmpty()) {
                continue
            }
            var t = s.last()
            ans += t.first
            res.add(Pair(t.second, -ev.id - 1))
            s.remove(t)
        } else {
            s.add(Pair(ev.cost, ev.id))
        }
    }
    println("${res.size} ${ans}")
    for (r in res) {
        println("${r.first + 1} ${r.second + 1}")
    }
}