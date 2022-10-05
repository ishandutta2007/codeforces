import java.util.*

fun main() {
    for (c in 1..readLine()!!.toInt()) {
        val line = readLine()!!
        val six = line.indexOf(' ')
        val n = line.substring(0, six).toInt()
        val k = line.substring(six + 1).toLong()
        val tokenizer = StringTokenizer(readLine()!!)
        val freq = LongArray(60)
        for (j in 1..n) {
            var a = tokenizer.nextToken().toLong()
            var e = 0
            while (a != 0L) {
                freq[e] += a % k
                e++
                a /= k
            }
        }
        println(if (freq.all { it <= 1L }) "yEs" else "nO")
    }
}