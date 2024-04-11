import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val students = Array(n) { ix -> Student(ix, jin.nextInt()) }
    students.sortBy { it.skill }
    val overall = students.last().skill - students.first().skill
    val diffs = IntArray(n - 3) { j -> students[j + 1].skill - students[j].skill }
    var maxSoFar = 0
    var maxIx = -1
    val dp = IntArray(n - 3)
    val prev = IntArray(n - 3) { -1 }
    for (j in 2..n - 4) {
        if (j >= 3 && dp[j - 3] > maxSoFar) {
            maxSoFar = dp[j - 3]
            maxIx = j - 3
        }
        dp[j] = diffs[j] + maxSoFar
        prev[j] = maxIx
    }
    var greatest = 0
    var greatestIx = -1
    for (j in 2..n - 4) {
        if (dp[j] > greatest) {
            greatest = dp[j]
            greatestIx = j
        }
    }
    val teams = IntArray(n)
    var j = greatestIx
    var team = 1
    for (k in n - 1 downTo 0) {
        if (k <= j) {
            team++
            j = prev[j]
        }
        teams[students[k].ix] = team
    }
    println("${overall - greatest} $team")
    println(teams.joinToString(" ", "", ""))
}

data class Student(val ix: Int, val skill: Int)