import kotlin.math.*

fun main() {
    val t = readLine()!!.toInt()
    for (i in 0 until t) {
        val s = readLine()!!
        val t = readLine()!!

        var maxLength = 0
        for (i in s.indices) {
            for (j in t.indices) {
                for (k in 0 until min(s.length - i, t.length - j)) {
                    if (s[i + k] != t[j + k]) {
                        break
                    } else {
                        maxLength = max(maxLength, k + 1)
                    }
                }
            }
        }

        println(s.length + t.length - 2 * maxLength)
    }
}