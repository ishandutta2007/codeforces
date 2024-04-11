fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        var answer = 1
        val athletes = arrayOf(listOf<Int>()) + Array(n) { readLine()!!.split(" ").map { it.toInt() } }
        fun better(x: Int, y: Int) = athletes[x].zip(athletes[y]).count { (a, b) -> a < b } >= 3
        for (j in 2..n) {
            if (better(j, answer)) {
                answer = j
            }
        }
        println(if ((1..n).all { j -> j == answer || better(answer, j) }) answer else -1)
    }
}