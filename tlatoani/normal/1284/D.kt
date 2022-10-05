import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val lectures = Array(n) {
        val tokenizer = StringTokenizer(readLine()!!)
        val x = tokenizer.nextToken().toInt()
        val y = tokenizer.nextToken().toInt()
        val u = tokenizer.nextToken().toInt()
        val v = tokenizer.nextToken().toInt()
        Lecture(x, y, u, v, it)
    }
    val events = Array(2 * n) { Event(lectures[it / 2], it % 2 == 0) }
    events.sortBy { if (it.add) (2 * it.lecture.x) else ((2 * it.lecture.y) + 1) }
    val uPQ = TreeSet<Pair<Int, Int>> { p1, p2 ->
        if (p1.first != p2.first) {
            p2.first - p1.first
        } else {
            p1.second - p2.second
        }
    }
    val vPQ = TreeSet<Pair<Int, Int>> { p1, p2 ->
        if (p1.first != p2.first) {
            p1.first - p2.first
        } else {
            p1.second - p2.second
        }
    }
    for (event in events) {
        if (event.add) {
            uPQ.add(Pair(event.lecture.u, event.lecture.z))
            vPQ.add(Pair(event.lecture.v, event.lecture.z))
        } else {
            uPQ.remove(Pair(event.lecture.u, event.lecture.z))
            vPQ.remove(Pair(event.lecture.v, event.lecture.z))
            if (uPQ.isNotEmpty() && uPQ.first().first > event.lecture.v) {
                println("nO")
                return
            }
            if (vPQ.isNotEmpty() && vPQ.first().first < event.lecture.u) {
                println("nO")
                return
            }
        }
    }
    events.sortBy { if (it.add) (2 * it.lecture.u) else ((2 * it.lecture.v) + 1) }
    val xPQ = TreeSet<Pair<Int, Int>> { p1, p2 ->
        if (p1.first != p2.first) {
            p2.first - p1.first
        } else {
            p1.second - p2.second
        }
    }
    val yPQ = TreeSet<Pair<Int, Int>> { p1, p2 ->
        if (p1.first != p2.first) {
            p1.first - p2.first
        } else {
            p1.second - p2.second
        }
    }
    for (event in events) {
        if (event.add) {
            xPQ.add(Pair(event.lecture.x, event.lecture.z))
            yPQ.add(Pair(event.lecture.y, event.lecture.z))
        } else {
            xPQ.remove(Pair(event.lecture.x, event.lecture.z))
            yPQ.remove(Pair(event.lecture.y, event.lecture.z))
            if (xPQ.isNotEmpty() && xPQ.first().first > event.lecture.y) {
                println("nO")
                return
            }
            if (yPQ.isNotEmpty() && yPQ.first().first < event.lecture.x) {
                println("nO")
                return
            }
        }
    }
    println("yEs")
}

data class Lecture(val x: Int, val y: Int, val u: Int, val v: Int, val z: Int)
data class Event(val lecture: Lecture, val add: Boolean)