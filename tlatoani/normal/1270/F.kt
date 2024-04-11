import kotlin.math.max

fun main() {
    val s = readLine()!!
    val n = s.length
    val sums = IntArray(n + 1)
    for (j in 1..n) {
        sums[j] = sums[j - 1] + (s[j - 1] - '0')
    }
    val freq = IntArray(41000000)
    val last = CharArray(41000000)
    var answer = 0L
    for (f in 1..200) {
        val chara = f.toChar()
        freq[n] = 1
        last[n] = chara
        for (j in 1..n) {
            val p = (f * sums[j]) - j + n
            if (last[p] != chara) {
                freq[p] = 0
                last[p] = chara
            } else {
                answer += freq[p].toLong()
            }
            freq[p]++
        }
    }
    for (a in 1..1000) {
        var r1 = 0
        var r2 = 0
        for (l in 0 until n) {
            while (r1 <= n && sums[r1] - sums[l] < a) {
                r1++
            }
            while (r2 <= n && sums[r2] - sums[l] <= a) {
                r2++
            }
            val minF = max(201, ((r1 - l - 1) / a) + 1)
            val maxF = max(201, ((r2 - l - 1) / a) + 1)
            answer += (maxF - minF).toLong()
        }
    }
    println(answer)
}