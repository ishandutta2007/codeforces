import kotlin.math.max

fun main() {
    val s = readLine()!!
    val t = readLine()!!
    val earliest = IntArray(t.length + 1)
    val latest = IntArray(t.length + 1)
    var k = 0
    for (j in 1..s.length) {
        if (s[j - 1] == t[k]) {
            k++
            earliest[k] = j
            if (k == t.length) {
                break
            }
        }
    }
    k = t.length
    latest[t.length] = s.length
    for (j in s.length - 1 downTo 0) {
        if (s[j] == t[k - 1]) {
            k--
            latest[k] = j
            if (k == 0) {
                break
            }
        }
    }
    var answer = 0
    for (j in 0..t.length) {
        answer = max(answer, latest[j] - earliest[j])
    }
    println(answer)
}