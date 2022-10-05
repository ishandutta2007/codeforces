import java.io.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val p = jin.readLine().substringAfterLast(' ').toInt()
    val f = jin.readLine().split(" ").map { it.toInt() }
    val g = jin.readLine().split(" ").map { it.toInt() }
    println(f.indexOf(f.first { it % p != 0 }) + g.indexOf(g.first { it % p != 0 }))
}