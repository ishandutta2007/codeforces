import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val tokenizer = StringTokenizer(readLine()!!)
    var sum = 0L
    val ps = Array(n + 1) {
        if (it > 0) {
            sum += tokenizer.nextToken().toInt()
        }
        Point(it.toLong(), sum)
    }
    val hull = ArrayList<Point>(n + 1)
    for (j in 0..n) {
        //println("hull = $hull")
        while (hull.size >= 2 && sideOfLine(hull[hull.size - 2], hull.last(), ps[j]) <= 0L) {
            hull.removeAt(hull.size - 1)
            //println("hull = $hull")
        }
        hull.add(ps[j])
    }
    //println("hull = $hull")
    val out = StringBuilder()
    for (j in 1 until hull.size) {
        val dx = hull[j].x - hull[j - 1].x
        val dy = hull[j].y - hull[j - 1].y
        val average = (dy.toDouble() / dx.toDouble()).toString()
        for (k in 1..dx) {
            out.appendln(average)
        }
    }
    print(out)
}

data class Point(val x: Long, val y: Long) {
    override fun toString() = "($x, $y)"
}

fun sideOfLine(a: Point, b: Point, p: Point): Long {
    val left = (b.x - a.x) * (p.y - a.y)
    val right = (b.y - a.y) * (p.x - a.x)
    return left - right
}