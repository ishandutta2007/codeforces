import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = jin.readLine().split(" ").map { it.toInt() }
    val edges = mutableMapOf<Pair<Int, Int>, Char>()
    var bothWays = 0
    var bothWaysSameCharacter = 0
    val out = StringBuilder()
    for (j in 1..m) {
        val query = jin.readLine().split(" ")
        when (query[0][0]) {
            '+' -> {
                val a = query[1].toInt()
                val b = query[2].toInt()
                val chara = query[3][0]
                val other = edges[Pair(b, a)]
                if (other != null) {
                    bothWays++
                    if (other == chara) {
                        bothWaysSameCharacter++
                    }
                }
                edges[Pair(a, b)] = chara
            }
            '-' -> {
                val a = query[1].toInt()
                val b = query[2].toInt()
                val chara = edges.remove(Pair(a, b))!!
                val other = edges[Pair(b, a)]
                if (other != null) {
                    bothWays--
                    if (other == chara) {
                        bothWaysSameCharacter--
                    }
                }
            }
            '?' -> {
                val k = query[1].toInt()
                out.appendln(if ((if (k % 2 == 1) bothWays else bothWaysSameCharacter) > 0) "yEs" else "nO")
            }
        }
    }
    print(out)
}