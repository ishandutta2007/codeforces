fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s1 = readLine()!!
        val s2 = readLine()!!
        val s = s1.map { it - '0' }.zip(s2.map { it - '0' }).map { (x, y) -> x + y }
        var answer = 0
        val isTaken = BooleanArray(n)
        for (j in 0 until n) {
            if (s[j] == 0) {
                answer++
            } else if (s[j] == 2) {
                if (j > 0 && s[j - 1] == 0 && !isTaken[j - 1]) {
                    answer++
                } else if (j < n - 1 && s[j + 1] == 0) {
                    answer++
                    isTaken[j + 1] = true
                }
            } else {
                answer += 2
            }
        }
        println(answer)
    }
}