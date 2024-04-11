import kotlin.math.min

fun main() {
    repeat(readLine()!!.toInt()) {
        val s = " " + readLine()!!
        var answer = 10
        for (favoredTeam in 0..1) {
            val favoredTeamSign = if (favoredTeam == 1) 1 else -1
            var difference = 0
            for (j in 1..10) {
                difference += when {
                    j % 2 == favoredTeam -> when {
                        s[j] != '0' -> favoredTeamSign
                        else -> 0
                    }
                    else -> when {
                        s[j] == '1' -> -favoredTeamSign
                        else -> 0
                    }
                }
                if (difference > (10 - j + 1) / 2 || -difference > (10 - j) / 2) {
                    answer = min(answer, j)
                }
            }
        }
        println(answer)
    }
}