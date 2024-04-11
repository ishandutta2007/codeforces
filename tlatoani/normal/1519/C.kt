import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val n = jin.readLine().toInt()
        val teams = mutableMapOf<Int, MutableList<Long>>()
        val teamTokenizer = StringTokenizer(jin.readLine())
        val skillTokenizer = StringTokenizer(jin.readLine())
        for (j in 1..n) {
            teams.computeIfAbsent(teamTokenizer.nextToken().toInt()) { mutableListOf() }.add(skillTokenizer.nextToken().toLong())
        }
        val answers = LongArray(n + 2)
        for (team in teams.values) {
            team.sortDescending()
            val sums = LongArray(team.size + 1)
            for (j in team.indices) {
                sums[j + 1] = sums[j] + team[j]
            }
            answers[1] += sums[team.size]
            for (k in 2..team.size + 1) {
                answers[k] += (sums[team.size - (team.size % k)]) - (sums[team.size - (team.size % (k - 1))])
            }
        }
        for (k in 1..n) {
            answers[k] += answers[k - 1]
        }
        out.appendln(answers.toList().subList(1, n + 1).joinToString(" "))
    }
    print(out)
}