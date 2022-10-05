fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val times = readLine()!!.split(" ").map { it.toLong() }.sortedDescending()
        var answer = times[0]
        var sum = times[0]
        for (j in 1 until n) {
            answer += (j.toLong() * times[j]) - sum
            sum += times[j]
        }
        println(answer)
    }
}