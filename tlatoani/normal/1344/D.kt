import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun inverse(a: Long, m: Long): Long {
    var upper = a - 1
    var lower = 0L
    while (upper > lower) {
        val mid = (upper + lower + 1) / 2L
        if (a - (3L * mid * mid) - (3L * mid) - 1L >= m) {
            lower = mid
        } else {
            upper = mid - 1L
        }
    }
    return upper
}

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val line = jin.readLine().split(" ")
    val k = line[1].toLong()
    val amts = jin.readLine().split(" ").map { it.toLong() }
    var upper = 1000000000L
    var lower = -4000000000000000000L
    fun interval(m: Long): Pair<Long, Long> {
        //println("m = $m")
        var l = 0L
        var r = 0L
        for (a in amts) {
            if ((-3L * a * a) + (4L * a) - 1L >= m) {
                //println("$a -> $a")
                l += a
                r += a
            } else if (a > m) {
                val b = inverse(a, m)
                l += if (a - (3L * b * b) - (3L * b) - 1L == m) {
                    //print("* ")
                    b
                } else {
                    b + 1L
                }
                //println("$a -> ${b + 1L}")
                r += b + 1L
            } else {
                //println("$a -> 0")
            }
        }
        return Pair(l, r)
    }
    while (upper > lower) {
        //println("upper = $upper, lower = $lower")
        val mid = (upper + lower) / 2L
        val inte = interval(mid)
        //println("mid = $mid -> $inte, k = $k")
        if (k < inte.first) {
            lower = mid + 1L
        } else if (k > inte.second) {
            upper = mid - 1L
        } else {
            upper = mid
            lower = mid
        }
    }
    val inte = interval(upper)
    var extra = inte.second - k
    val answer = StringJoiner(" ")
    for (a in amts) {
        if ((-3L * a * a) + (4L * a) - 1L > upper) {
            answer.add(a.toString())
        } else if (a > upper) {
            val b = inverse(a, upper)
            answer.add((if (a - (3L * b * b) - (3L * b) - 1L == upper && extra > 0L) {
                extra--
                b
            } else {
                b + 1L
            }).toString())
        } else {
            answer.add("0")
        }
    }
    println(answer)
}