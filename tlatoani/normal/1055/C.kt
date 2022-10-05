import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.max
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    var (la, ra, ta) = jin.readLine().split(" ").map { it.toLong() }
    var (lb, rb, tb) = jin.readLine().split(" ").map { it.toLong() }
    val g = gcd(ta, tb)
    val sa = ra - la
    val sb = rb - lb
    la %= g
    lb %= g
    val answer = max(
            max(
                    min(la + sa, lb + sb) - max(la, lb),
                    min(la + sa + g, lb + sb) - max(la + g, lb)),
            max(
                    min(la + sa, lb + sb + g) - max(la, lb + g),
                    -1L)
    ) + 1L
    println(answer)
}

fun gcd(a: Long, b: Long): Long = if (b == 0L) a else gcd(b, a % b)