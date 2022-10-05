import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val points = Array(n) { k ->
        val x = jin.nextInt()
        val y = jin.nextInt()
        val z = jin.nextInt()
        Point(k + 1, x, y, z)
    }
    points.sort()
    //println(points.contentToString())
    val rem = mutableListOf<Point>()
    var i = 0
    while (i < n) {
        if (i == n - 1) {
            rem.add(points[n - 1])
            break
        }
        if (points[i].x == points[i + 1].x && points[i].y == points[i + 1].y) {
            println("${points[i].k} ${points[i + 1].k}")
            i += 2
        } else {
            rem.add(points[i])
            i++
        }
    }
    i = 0
    val rem2 = mutableListOf<Point>()
    while (i < rem.size) {
        if (i == rem.size - 1) {
            rem2.add(rem.last())
            break
        }
        if (rem[i].x == rem[i + 1].x) {
            println("${rem[i].k} ${rem[i + 1].k}")
            i += 2
        } else {
            rem2.add(rem[i])
            i++
        }
    }
    i = 0
    while (i < rem2.size) {
        println("${rem2[i].k} ${rem2[i + 1].k}")
        i += 2
    }
}

data class Point(val k: Int, val x: Int, val y: Int, val z: Int): Comparable<Point> {
    override fun compareTo(other: Point) = compareValuesBy(this, other, { it.x }, { it.y }, { it.z })
}