import java.util.*

fun main() {
    var t = read()
    repeat(t) {
        var n = read()
        var l = readv()
        var r = readv()
        var la = l.sortedBy { it }
        var s = 0
        var lr2 : MutableList<Pair<Int, Int>> = mutableListOf()

        for(i in 0 until n) {
            lr2.add(Pair(l[i], i))
            s = maxOf(s, la[i] - i)
        }
        var lr = lr2.sortedBy { it.first }
//        var es : MutableSet<Pair<Int, Int>> = mutableSetOf()
        var es = TreeSet<Pair<Int, Int>> (compareBy ({it.first}, {it.second}))
//        var es =
//        var es = PriorityQueue<Pair<Int, Int>> (compareBy { it.first })
        var pt = 0
        var can = 1
        var ans = Array(n, {-1})
        for(cur in s until s + n) {
            while(pt<n && lr[pt].first <= cur) {
                var i = lr[pt].second
//                println("min $cur addded ${i+1} ${r[i]}")
                es.add(Pair(r[i], i))
//                println(es)
//                es.add(Pair(r[i], i))
                pt++
            }
//            println(es)
            if(es.isEmpty() || es.first().first < cur) {
//            if(es.peek().first < cur) {
                can = 0
                break
            }
            else {
//                println(es)
//                println(es.indexOfFirst({}))
                ans[cur-s] = es.first().second + 1
                es.remove(es.first())
//                println("removed top")
//                println(es)
//                es.poll()
//                es.remove(es.elementAt(0))
            }
        }
        if(can == 0) println(-1)
        else {
            println(s)
            println(ans.joinToString(" "))
        }
//        println(s)
//        println(a)
//        println(l)
    }
}

private fun read() = readLine()!!.toInt()
private fun readv() = readLine()!!.split(" ").map {it.toInt()}