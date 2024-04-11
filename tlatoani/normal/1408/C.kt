import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val (n, l) = jin.readLine().split(" ").map { it.toInt() }
        val flags = listOf(.0) + jin.readLine().split(" ").map { it.toDouble() } + listOf(l.toDouble())
        val flagsRev = flags.reversed().map { -it }
        var upper = l.toDouble()
        var lower = .0
        while (upper - lower > .0000001) {
            val mid = (upper + lower) / 2.0
            var dist = l.toDouble()
            var t = mid
            for (j in 1..n + 1) {
                if (flags[j] - flags[j - 1] < j.toDouble() * t) {
                    dist -= flags[j] - flags[j - 1]
                    t -= (flags[j] - flags[j - 1]) / j.toDouble()
                } else {
                    dist -= j.toDouble() * t
                    break
                }
            }
            t = mid
            for (j in 1..n + 1) {
                if (flagsRev[j] - flagsRev[j - 1] < j.toDouble() * t) {
                    dist -= flagsRev[j] - flagsRev[j - 1]
                    t -= (flagsRev[j] - flagsRev[j - 1]) / j.toDouble()
                } else {
                    dist -= j.toDouble() * t
                    break
                }
            }
            if (dist <= .0) {
                upper = mid
            } else {
                lower = mid
            }
        }
        out.appendln(upper)
    }
    print(out)
}