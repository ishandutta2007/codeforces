import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val n = line.substring(0, six).toInt()
        var d = line.substring(six + 1).toInt()
        val tokenizer = StringTokenizer(readLine()!!)
        var answer = 0
        for (j in 0 until n) {
            var haybales = tokenizer.nextToken().toInt()
            while (haybales > 0 && d >= j) {
                haybales--
                answer++
                d -= j
            }
        }
        println(answer)
    }
}