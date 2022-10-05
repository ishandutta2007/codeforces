import java.util.*
import kotlin.math.abs
import kotlin.math.sign

fun main() {
    val n = readLine()!!.toInt()
    val ps = Array(n) {
        val tokenizer = StringTokenizer(readLine()!!)
        val x = tokenizer.nextToken().toLong()
        val y = tokenizer.nextToken().toLong()
        Point(x, y, .0)
    }
    var answer = 0L
    val nl = n.toLong()
    val all = ((nl - 1L) * (nl - 2L) * (nl - 3L)) / 6L
    for (j in 0 until n) {
        val c = ps[j]
        val qs = mutableListOf<Point>()
        for (k in 0 until n) {
            if (k != j) {
                qs.add(ps[k])
            }
        }
        qs.sortWith(kotlin.Comparator { b, d ->
            val bx = b.x - c.x
            val by = b.y - c.y
            val dx = d.x - c.x
            val dy = d.y - c.y
            if (by == 0L && bx > 0L) {
                -1
            } else if (dy == 0L && dx > 0L) {
                1
            } else if (by.sign != dy.sign) {
                dy.sign - by.sign
            } else if (bx.sign != dx.sign) {
                if (by < 0) {
                    bx.sign - dx.sign
                } else {
                    dx.sign - bx.sign
                }
            } else {
                if ((bx * by).sign == 1) {
                    abs(by * dx).compareTo(abs(dy * bx))
                } else {
                    abs(dy * bx).compareTo(abs(by * dx))
                }
            }
        })
        var l = 0
        var complement = 0L
        for (k in 0 until n - 1) {
            qs.add(qs[k])
            while (l < k + n - 1 && sideOfLine(c, qs[k], qs[l]) != -1) {
                l++
            }
            val a = (l - k - 1).toLong()
            complement += (a * (a - 1L)) / 2L
        }
        answer += all - complement
    }
    //println("total = $answer")
    answer *= nl - 4L
    answer /= 2L
    println(answer)
}

data class Point(val x: Long, val y: Long, val theta: Double) {
    override fun toString() = "($x, $y)"
}

fun sideOfLine(a: Point, b: Point, p: Point): Int {
    val left = (b.x - a.x) * (p.y - a.y)
    val right = (b.y - a.y) * (p.x - a.x)
    return when {
        left > right -> 1
        left == right -> 0
        else -> -1
    }
}