import java.util.*
import kotlin.math.max

fun main() {
    val jin = Scanner(System.`in`)
    val m = jin.nextInt()
    val n = jin.nextInt()
    val k = jin.nextInt()
    val t = jin.nextInt()
    val agilities = Array(m) { jin.nextInt() }
    agilities.sort()
    val traps = Array(k) {
        val l = jin.nextInt()
        val r = jin.nextInt()
        val d = jin.nextInt()
        Trap(l, r, d)
    }
    var upper = m
    var lower = 0
    while (upper > lower) {
        var mid = (upper + lower + 1) / 2
        val locs = IntArray(n + 1)
        for (trap in traps) {
            if (mid > 0 && trap.d > agilities[m - mid]) {
                locs[trap.l] = max(locs[trap.l], trap.r)
            }
        }
        var res = n + 1
        for (x in 0 until n) {
            if (locs[x + 1] != 0) {
                var until = locs[x + 1]
                var y = x
                while (y < until) {
                    y++
                    if (y <= n && locs[y] != 0) {
                        until = max(until, locs[y])
                        locs[y] = 0
                    }
                }
                res += 2 * (y - x)
            }
        }
        //println("mid = $mid, res = $res")
        if (res <= t) {
            lower = mid
        } else {
            upper = mid - 1
        }
    }
    println(upper)
}

data class Trap(val l: Int, val r: Int, val d: Int)