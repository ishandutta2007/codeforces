import kotlin.math.abs
import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val xs = readLine()!!.split(" ").map { it.toInt() }
        val ys = xs.map { it - xs.min()!! }
        if (ys.any { y -> ys.count { it == y} >= n / 2 }) {
            println(-1)
        } else {
            var answer = 1
            for (j in 0 until n) {
                for (k in j + 1 until n) {
                    val d = abs(ys[j] - ys[k])
                    if (d != 0) {
                        val factors = mutableListOf<Int>()
                        for (f in 1..1000) {
                            if (f * f > d) {
                                break
                            }
                            if (d % f == 0) {
                                factors.add(f)
                                factors.add(d / f)
                            }
                        }
                        for (f in factors) {
                            var here = 0
                            for (y in ys) {
                                if (abs(y - ys[j]) % f == 0) {
                                    here++
                                }
                            }
                            if (here >= n / 2) {
                                answer = max(answer, f)
                            }
                        }
                    }
                }
            }
            println(answer)
        }
    }
}