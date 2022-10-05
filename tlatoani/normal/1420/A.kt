import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val cubes = jin.readLine().split(" ").map { it.toInt() }
        if (cubes.toSet().size == n && cubes == cubes.sortedDescending()) {
            println("NO")
        } else {
            println("YES")
        }
    }
}