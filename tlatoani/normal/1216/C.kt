import java.util.*
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = Scanner(System.`in`)
    fun readRectangle(): Rectangle {
        val x1 = jin.nextLong()
        val y1 = jin.nextLong()
        val x2 = jin.nextLong()
        val y2 = jin.nextLong()
        return Rectangle(x1, x2, y1, y2)
    }
    val white = readRectangle()
    val black1 = readRectangle()
    val black2 = readRectangle()
    val rem = white.area() - white.intersection(black1).area() - white.intersection(black2).area() + white.intersection(black1).intersection(black2).area()
    println(if (rem > 0L) "YES" else "NO")
}

data class Rectangle(val x1: Long, val x2: Long, val y1: Long, val y2: Long) {
    fun area() = (x2 - x1) * (y2 - y1)
    fun intersection(other: Rectangle): Rectangle {
        if (other.x1 >= x2 || x1 >= other.x2 || other.y1 >= y2 || y1 >= other.y2) {
            return Rectangle(-1L, -1L, -1L, -1L)
        }
        return Rectangle(max(x1, other.x1), min(x2, other.x2), max(y1, other.y1), min(y2, other.y2))
    }
}