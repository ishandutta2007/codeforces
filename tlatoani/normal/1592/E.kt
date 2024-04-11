import kotlin.math.max

fun main() {
    val n = readLine()!!.toInt()
    val ay = listOf(0) + readLine()!!.split(" ").map { it.toInt() }
    val trie = IntArray(1 shl 21) { -1 }
    var answer = 0
    var currXOR = 0
    for (e in 0..19) {
        trie[1 shl (20 - e)] = 0
    }
    for (j in 1..n) {
        currXOR = currXOR xor ay[j]
        for (e in 0..19) {
            trie[((1 shl 20) xor currXOR) shr e] = j
        }
        var a = ay[j]
        var b = ay[j] and (if (j == n) 0 else ay[j + 1])
        var prevXOR = currXOR
        for (k in j downTo 1) {
            prevXOR = prevXOR xor ay[k]
            a = a and ay[k]
            b = b and ay[k]
            if (a == b) {
                break
            }
            for (e in 0..19) {
                if ((a shr e) and 1 == 1) {
                    answer = max(answer, trie[(((1 shl 20) xor prevXOR xor a) shr e) xor 1] - k + 1)
                }
            }
        }
    }
    println(answer)
}