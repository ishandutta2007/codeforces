import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val x = 500000000
    var y = 1
    fun query(): String {
        println("$x $y")
        return jin.next()
    }
    val initial = query()
    for (e in n - 2 downTo 0) {
        y += 1 shl e
        if (query() != initial) {
            y -= 1 shl e
        }
    }
    println("${x - 1} $y ${x + 1} ${y + 1}")
}