import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    var points = Array(n) {
        val line = jin.readLine()
        Point(line.last(), line.substring(0, line.length - 2).toLong())
    }
    var answer = 0L
    if (points.any { it.color == 'G' }) {
        answer += points.maxBy { if (it.color == 'G') it.x else Long.MIN_VALUE }!!.x
        answer -= points.minBy { if (it.color == 'G') it.x else Long.MAX_VALUE }!!.x
        points = arrayOf(Point('G', -3000000000L)) + points + arrayOf(Point('G', 3000000000L))
        answer -= points.last().x - points.first().x
        var lg = points[0].x
        var lr = points[0].x
        var lb = points[0].x
        var mr = 0L
        var mb = 0L
        for (j in 1..n + 1) {
            if (points[j].color != 'B') {
                mr = max(mr, points[j].x - lr)
                lr = points[j].x
            }
            if (points[j].color != 'R') {
                mb = max(mb, points[j].x - lb)
                lb = points[j].x
            }
            if (points[j].color == 'G') {
                answer += min((3L * (points[j].x - lg)) - mr - mb, 2L * (points[j].x - lg))
                mr = 0L
                mb = 0L
                lg = points[j].x
            }
        }
    } else {
        if (points.any { it.color == 'R' }) {
            answer += points.maxBy { if (it.color == 'R') it.x else Long.MIN_VALUE }!!.x
            answer -= points.minBy { if (it.color == 'R') it.x else Long.MAX_VALUE }!!.x
        }
        if (points.any { it.color == 'B' }) {
            answer += points.maxBy { if (it.color == 'B') it.x else Long.MIN_VALUE }!!.x
            answer -= points.minBy { if (it.color == 'B') it.x else Long.MAX_VALUE }!!.x
        }
    }
    println(answer)
}

data class Point(val color: Char, val x: Long)

/*
6
4 R
11 G
15 R
20 B
25 G
30 B

 */

/*
5
1 R
4 B
9 R
16 R
25 B
 */