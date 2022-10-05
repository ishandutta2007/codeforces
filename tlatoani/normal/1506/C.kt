import kotlin.math.min

fun main() {
    cases@for (c in 1..readLine()!!.toInt()) {
        val a = readLine()!!
        val b = readLine()!!
        var answer = a.length + b.length
        for (j in a.indices) {
            for (k in b.indices) {
                var curr = a.length + b.length
                for (l in 0 until min(a.length - j, b.length - k)) {
                    if (a[j + l] == b[k + l]) {
                        curr -= 2
                    } else {
                        break
                    }
                }
                answer = min(answer, curr)
            }
        }
        println(answer)
    }
}