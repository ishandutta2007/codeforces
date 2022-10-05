import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*
import kotlin.math.min

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    for (c in 1..jin.readLine().toInt()) {
        val tokenizer = StringTokenizer(jin.readLine())
        val n = tokenizer.nextToken().toInt()
        val m = tokenizer.nextToken().toInt()
        var grid = Array(n) { jin.readLine().toCharArray() }
        if (grid.all { !it.contains('P') }) {
            println(0)
            continue
        }
        var answer = 5
        for (y in 0 until n) {
            val d = if (y == 0 || y == n - 1) -1 else 0
            answer = min(answer, d + when {
                !grid[y].contains('P') -> 2
                grid[y][0] == 'A' || grid[y].last() == 'A' -> 3
                grid[y].contains('A') -> 4
                else -> 6
            })
        }
        grid = Array(m) { x -> CharArray(n) { y -> grid[y][x] } }
        for (x in 0 until m) {
            val d = if (x == 0 || x == m - 1) -1 else 0
            answer = min(answer, d + when {
                !grid[x].contains('P') -> 2
                grid[x][0] == 'A' || grid[x].last() == 'A' -> 3
                grid[x].contains('A') -> 4
                else -> 6
            })
        }
        println(if (answer == 5) "MORTAL" else answer)
    }
}