import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.system.exitProcess

fun main() {
    fun factors(m: Int): List<Int> {
        val res = mutableListOf<Int>()
        for (f in 1..1000) {
            if (m % f == 0) {
                res.add(f)
                if (f * f != m) {
                    res.add(m / f)
                }
            }
        }
        return res
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (k, n) = jin.readLine().split(" ").map { it.toInt() }
    val periods = jin.readLine().split(" ").map { it.toInt() }.toSet()
    val pois = jin.readLine().split(" ").map { it.toInt() }
    if (n == 2) {
        println("yEs")
        println("${pois[0]} ${periods.min()}")
        println("${pois[1]} ${periods.min()}")
        exitProcess(0)
    } else {
        fun attempt(start: Int, multiple: Int) {
            for (f in factors(multiple)) {
                if (f in periods) {
                    var other = -1
                    var otherPeriod = 0
                    for (poi in pois) {
                        if (poi % f != start % f) {
                            if (other == -1) {
                                other = poi
                            } else {
                                otherPeriod = gcd(otherPeriod, poi - other)
                            }
                        }
                    }
                    if (other == -1) {
                        println("yEs")
                        println("$start $f")
                        println("1 ${periods.min()}")
                        exitProcess(0)
                    }
                    for (g in factors(otherPeriod)) {
                        if (g in periods) {
                            println("yEs")
                            println("$start $f")
                            println("$other $g")
                            exitProcess(0)
                        }
                    }
                }
            }
        }
        attempt(pois[0], pois[1] - pois[0])
        attempt(pois[0], pois[2] - pois[0])
        attempt(pois[1], pois[2] - pois[1])
    }
    println("nO")
}

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)