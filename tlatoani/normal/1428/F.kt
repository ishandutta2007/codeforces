import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val s = readLine()!!
    var answer = 0L
    val longest = LongArray(n)
    fun recur(from: Int, to: Int) {
        if (from > to) {
            return
        }
        var mid = (from + to) / 2
        while (mid > from && s[mid] == '1') {
            mid--
        }
        if (s[mid] == '1') {
            mid = (from + to) / 2
            while (mid < to && s[mid] == '1') {
                mid++
            }
        }
        if (s[mid] == '1') {
            val lambda = (to - from + 1).toLong()
            answer += (lambda * (lambda + 1L) * (lambda + 2L)) / 6L
        } else {
            var curr = 0L
            longest[mid] = 0L
            for (j in mid - 1 downTo from) {
                if (s[j] == '1') {
                    curr++
                } else {
                    curr = 0L
                }
                longest[j] = max(curr, longest[j + 1])
            }
            curr = 0L
            longest[mid] = 0L
            for (j in mid + 1..to) {
                if (s[j] == '1') {
                    curr++
                } else {
                    curr = 0L
                }
                longest[j] = max(curr, longest[j - 1])
            }
            var k = mid
            for (j in mid downTo from) {
                while (k <= to && longest[k] <= longest[j]) {
                    k++
                }
                answer += longest[j] * (k - mid).toLong()
            }
            k = mid
            for (j in mid..to) {
                while (k >= from && longest[k] < longest[j]) {
                    k--
                }
                answer += longest[j] * (mid - k).toLong()
            }
            recur(from, mid - 1)
            recur(mid + 1, to)
        }
    }
    recur(0, n - 1)
    println(answer)
}