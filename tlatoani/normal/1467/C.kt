import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    jin.readLine()
    val sums = mutableListOf<Long>()
    val mins = mutableListOf<Long>()
    for (j in 0..2) {
        val ay = jin.readLine().split(" ").map { it.toLong() }
        sums.add(ay.sum())
        mins.add(ay.min()!!)
    }
    println(sums.sum() - (2L * min(sums.min()!!, mins.sum() - mins.max()!!)))
}