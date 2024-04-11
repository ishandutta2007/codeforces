import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val ps = Array(n) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        Point(line.substring(0, six).toInt(), line.substring(six + 1).toInt())
    }
    while (true) {
        var p0 = 0
        var p1 = 0
        for (p in ps) {
            if ((p.x + p.y) % 2 == 0) {
                p0++
            } else {
                p1++
            }
        }
        if (p0 != 0 && p1 != 0) {
            println(p0)
            val joiner = StringJoiner(" ")
            for (j in 0 until n) {
                if ((ps[j].x + ps[j].y) % 2 == 0) {
                    joiner.add((j + 1).toString())
                }
            }
            println(joiner)
            return
        }
        p0 = 0
        p1 = 0
        for (p in ps) {
            if (p.x % 2 == 0) {
                p0++
            } else {
                p1++
            }
        }
        if (p0 != 0 && p1 != 0) {
            println(p0)
            val joiner = StringJoiner(" ")
            for (j in 0 until n) {
                if (ps[j].x % 2 == 0) {
                    joiner.add((j + 1).toString())
                }
            }
            println(joiner)
            return
        }
        for (p in ps) {
            if (p.x % 2 == 0) {
                p.x /= 2
            } else {
                p.x = (p.x + 1) / 2
            }
            if (p.y % 2 == 0) {
                p.y /= 2
            } else {
                p.y = (p.y + 1) / 2
            }
        }
    }
}

class Point(var x: Int, var y: Int)