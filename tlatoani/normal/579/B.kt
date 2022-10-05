import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val teams = mutableListOf<Team>()
    for (j in 2..2 * n) {
        val tokenizer = StringTokenizer(jin.readLine())
        for (k in 1 until j) {
            teams.add(Team(j, k, tokenizer.nextToken().toInt()))
        }
    }
    teams.sortByDescending { it.strength }
    val answer = IntArray((2 * n) + 1)
    for (team in teams) {
        if (answer[team.j] == 0 && answer[team.k] == 0) {
            answer[team.j] = team.k
            answer[team.k] = team.j
        }
    }
    println(answer.joinToString(" ").substring(2))
}

data class Team(val j: Int, val k: Int, val strength: Int)