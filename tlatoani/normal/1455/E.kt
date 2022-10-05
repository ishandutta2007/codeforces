import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val ps = Array(4) { readLine()!!.split(" ").map { it.toLong() } }
        var answer = Long.MAX_VALUE
        for (a in 0..3) {
            for (b in 0..3) {
                for (c in 0..3) {
                    for (d in 0..3) {
                        if (setOf(a, b, c, d).size == 4) {
                            val (xa, ya) = ps[a]
                            val (xb, yb) = ps[b]
                            val (xc, yc) = ps[c]
                            val (xd, yd) = ps[d]
                            val bottom = Bump(abs(xb - xa), min(xa, xb), max(xa, xb))
                            val top = Bump(abs(xd - xc), min(xc, xd), max(xc, xd))
                            val left = Bump(abs(yc - ya), min(ya, yc), max(ya, yc))
                            val right = Bump(abs(yd - yb), min(yb, yd), max(yb, yd))
                            val horizontal = Bump(
                                    bottom.min + top.min,
                                    if (bottom.to >= top.from && top.to >= bottom.from) 0L else min(abs(top.to - bottom.from), abs(bottom.to - top.from)),
                                    max(bottom.to, top.to) - min(bottom.from, top.from))
                            val vertical = Bump(
                                    left.min + right.min,
                                    if (left.to >= right.from && right.to >= left.from) 0L else min(abs(right.to - left.from), abs(left.to - right.from)),
                                    max(left.to, right.to) - min(left.from, right.from))
                            val pos = horizontal.min + vertical.min + (if (horizontal.to >= vertical.from && vertical.to >= horizontal.from) 0L else (2L * min(abs(vertical.to - horizontal.from), abs(horizontal.to - vertical.from))))
                            answer = min(answer, pos)
                        }
                    }
                }
            }
        }
        println(answer)
    }
}

data class Bump(val min: Long, val from: Long, val to: Long)