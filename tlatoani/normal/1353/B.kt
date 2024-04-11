import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val line = jin.readLine().split(" ")
        val n = line[0].toInt()
        val k = line[1].toInt()
        val array = jin.readLine().split(" ").map { it.toInt() }.sortedDescending()
        val brray = jin.readLine().split(" ").map { it.toInt() }.sortedDescending()
        println((array + brray.subList(0, k)).sortedDescending().subList(0, n).sum())
    }
}