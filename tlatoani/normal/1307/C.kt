import kotlin.math.max

fun main() {
    val s = readLine()!!
    val freq1 = LongArray(26)
    val freq2 = Array(26) { LongArray(26) }
    for (chara in s) {
        val j = chara - 'a'
        for (k in 0..25) {
            freq2[k][j] += freq1[k]
        }
        freq1[j]++
    }
    var answer = 0L
    for (k in 0..25) {
        answer = max(answer, freq1[k])
        for (j in 0..25) {
            answer = max(answer, freq2[k][j])
        }
    }
    println(answer)
}