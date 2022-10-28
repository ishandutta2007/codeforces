import kotlin.math.*

fun main() {
    repeat(readLine()!!.toInt()) {
        var minK = 0
        var maxK = Int.MAX_VALUE

        repeat(readLine()!!.toInt()) {
            val (s, t, r) = readLine()!!.split(" ")

            var ptr = 0
            while (ptr < s.length && ptr < t.length && s[s.length - ptr - 1] == t[t.length - ptr - 1]) {
                ptr++
            }

            if (r == "1") {
                maxK = min(maxK, ptr)
            } else {
                minK = max(minK, ptr + 1)
            }
        }

        println(max(0, maxK - minK + 1))
        println((minK..maxK).joinToString(" "))
    }
}