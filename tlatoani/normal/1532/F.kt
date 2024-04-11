fun main() {
    val n = readLine()!!.toInt()
    val strings = mutableListOf<String>()
    val all = mutableListOf<String>()
    repeat((2 * n) - 2) {
        val s = readLine()!!
        all.add(s)
        if (s.length == n - 1) {
            strings.add(s)
        }
    }
    for (pos in listOf(strings[0].first() + strings[1], strings[1].first() + strings[0])) {
        val answer = attempt(all, pos)
        if (answer != null) {
            println(answer)
            return
        }
    }
}

fun attempt(all: List<String>, whole: String): String? {
    val seen = BooleanArray(whole.length)
    val answer = StringBuilder()
    for (s in all) {
        if (whole.startsWith(s) && !seen[s.length]) {
            answer.append('P')
            seen[s.length] = true
        } else if (whole.endsWith(s)) {
            answer.append('S')
        } else {
            return null
        }
    }
    return answer.toString()
}