import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val (sx, sy, fx, fy) = jin.readLine().split(" ").map { it.toInt() }
    val zSet = mutableSetOf<Int>()
    zSet.add(sx)
    zSet.add(sy)
    zSet.add(fx)
    zSet.add(fy)
    val spawns = Array(m) {
        val (x, y) = jin.readLine().split(" ").map { it.toInt() }
        zSet.add(x)
        zSet.add(y)
        Pair(x, y)
    }
    val zs = zSet.toList().sorted()
    val zix = mutableMapOf<Int, Int>()
    for ((j, z) in zs.withIndex()) {
        zix[z] = j
    }
    val spawnsX = Array(zs.size) { mutableListOf<Int>() }
    val spawnsY = Array(zs.size) { mutableListOf<Int>() }
    for (spawn in spawns) {
        val x = zix[spawn.first]!!
        val y = zix[spawn.second]!!
        spawnsX[x].add(y)
        spawnsY[y].add(x)
    }
    val zl = zs.map { it.toLong() }
    val pq = PriorityQueue<Line>(compareBy { it.dist })
    val distX = LongArray(zix.size) { Long.MAX_VALUE }
    val distY = LongArray(zix.size) { Long.MAX_VALUE }
    val seenX = BooleanArray(zix.size)
    val seenY = BooleanArray(zix.size)
    distX[zix[sx]!!] = 0L
    distY[zix[sy]!!] = 0L
    pq.add(Line(true, zix[sx]!!, 0L))
    pq.add(Line(false, zix[sy]!!, 0L))
    var answer = (abs(sx - fx) + abs(sy - fy)).toLong()
    //println("answer = $answer")
    while (pq.isNotEmpty()) {
        val (isX, z, dist) = pq.remove()
        if (isX) {
            if (!seenX[z]) {
                seenX[z] = true
                //println("x = ${zl[z]} has distance $dist")
                if (z > 0 && distX[z] + zl[z] - zl[z - 1] < distX[z - 1]) {
                    distX[z - 1] = distX[z] + zl[z] - zl[z - 1]
                    pq.add(Line(true, z - 1, distX[z - 1]))
                }
                if (z < zl.size - 1 && distX[z] + zl[z + 1] - zl[z] < distX[z + 1]) {
                    distX[z + 1] = distX[z] + zl[z + 1] - zl[z]
                    pq.add(Line(true, z + 1, distX[z + 1]))
                }
                for (y in spawnsX[z]) {
                    answer = min(answer, distX[z] + abs(zl[z] - fx) + abs(zl[y] - fy))
                    if (distY[y] > distX[z]) {
                        distY[y] = distX[z]
                        pq.add(Line(false, y, distY[y]))
                    }
                }
            }
        } else {
            if (!seenY[z]) {
                seenY[z] = true
                //println("y = ${zl[z]} has distance $dist")
                if (z > 0 && distY[z] + zl[z] - zl[z - 1] < distY[z - 1]) {
                    distY[z - 1] = distY[z] + zl[z] - zl[z - 1]
                    pq.add(Line(false, z - 1, distY[z - 1]))
                }
                if (z < zl.size - 1 && distY[z] + zl[z + 1] - zl[z] < distY[z + 1]) {
                    distY[z + 1] = distY[z] + zl[z + 1] - zl[z]
                    pq.add(Line(false, z + 1, distY[z + 1]))
                }
                for (x in spawnsY[z]) {
                    answer = min(answer, distY[z] + abs(zl[x] - fx) + abs(zl[z] - fy))
                    //println("answer = $answer")
                    if (distX[x] > distY[z]) {
                        distX[x] = distY[z]
                        pq.add(Line(true, x, distX[x]))
                    }
                }
            }
        }
    }
    println(answer)
}

data class Line(val isX: Boolean, val z: Int, val dist: Long)