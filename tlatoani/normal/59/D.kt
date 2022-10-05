import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val p = listOf(0) + jin.readLine().split(" ").map { it.toInt() }
    val q = IntArray((3 * n) + 1)
    for (j in 1..3 * n) {
        q[p[j]] = j
    }
    val teams = Array(n) { jin.readLine().split(" ").map { it.toInt() }.sortedBy { j -> q[j] } }
    teams.sortBy { q[it[0]] }
    val k = jin.readLine().toInt()
    val disp = TreeSet<Int>()
    for (team in teams) {
        if (team[0] == k) {
            val other = mutableListOf<Int>()
            other.add(team[1])
            other.add(team[2])
            other.sort()
            for (j in 1..3 * n) {
                if (j !in disp && j !in team) {
                    other.add(j)
                }
            }
            val dispList = disp.toList()
            val answer = mutableListOf<Int>()
            var a = 0
            var b = 0
            while (a < dispList.size || b < other.size) {
                if (a < dispList.size && (b == other.size || dispList[a] < other[b])) {
                    answer.add(dispList[a])
                    a++
                } else {
                    answer.add(other[b])
                    b++
                }
            }
            println(answer.joinToString(" "))
            return
        } else if (team[1] == k || team[2] == k) {
            val answer = (1..3 * n).toMutableList()
            answer.remove(k)
            println(answer.joinToString(" "))
            return
        }
        disp.addAll(team)
    }
}