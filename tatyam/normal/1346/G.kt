import java.util.*
import kotlin.math.*
import kotlin.system.exitProcess
import kotlin.system.measureNanoTime

val scanner = Scanner(System.`in`)
val INF = 0x3fffffff

fun center(a : MutableList<Long>) : Long {
    val n = a.size
    val s = MutableList(n + 1) { 0L }
    for (i in 1..n) s[i] = s[i - 1] + a[i - 1]
    var cen = 0
    for (i in 1..n) if(s[i] * 2 >= s.last()) {
        cen = i - 1
        break
    }
    var ans = 0L
    for (i in 0 until n) ans += a[i] * abs(i - cen)
    return ans
}

fun answer(p1 : Int, r1 : Int, p2 : Int, r2 : Int) {
    println("YES")
    println("${if (r1 == 0) p1 else r1} $p1")
    println("${if (r2 == 0) p2 else r2} $p2")
    exitProcess(0)
}


fun main() {
    val k = scanner.nextInt()
    val n = scanner.nextInt()
    val p = MutableList(k) { scanner.nextInt() }
    val x = MutableList(n) { scanner.nextInt() }
    var time = 0L
    if (n == 2) answer(p[0], x[0], p[0], x[1])
    while (time < 2_500_000_000) {
        time += measureNanoTime {
            val x1 = (0 until n).random()
            val x2 = (1 until n).random()
            if (x1 == x2) return@measureNanoTime
            val d1 = x[x2] - x[x1]
            for (p1 in p) if (d1 % p1 == 0) {
                val r1 = x[x1] % p1
                val y = mutableListOf<Int>()
                for (i in 0 until n) if (x[i] % p1 != r1) y.add(x[i])
                if (y.isEmpty()) answer(p1, r1, p[0], 1)
                if (y.size == 1) answer(p1, r1, p[0], y[0])
                val d2 = y[1] - y[0]
                for (p2 in p) if (d2 % p2 == 0) {
                    val r2 = y[0] % p2
                    if (y.all { i -> i % p2 == r2 }) answer(p1, r1, p2, r2)
                }
            }
        }
    }
    println("NO")
}