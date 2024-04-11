import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val words = Array(n) { readLine()!! }
        var answer = 0
        for (letter in 'a'..'e') {
            val ds = words.map { it.sumBy { if (it == letter) 1 else -1 } }.sortedDescending()
            if (ds[0] <= 0) {
                continue
            }
            var totalD = 0
            var words = 0
            for (d in ds) {
                if (totalD + d > 0) {
                    totalD += d
                    words++
                }
            }
            answer = max(answer, words)
        }
        println(answer)
    }
}