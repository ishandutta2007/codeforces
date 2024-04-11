fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        if (n == 1) {
            println(-1)
        } else {
            val answer = StringBuilder()
            answer.append(2)
            for (j in 2..n) {
                answer.append(3)
            }
            println(answer)
        }
    }
}