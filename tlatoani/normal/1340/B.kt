import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

val DIGITS = arrayOf("1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011")
val BITMASKS = DIGITS.map { it.toInt(2) }

fun main() {
    val bitAMT = IntArray(128)
    for (mask in 1..127) {
        bitAMT[mask] = bitAMT[mask - (mask and -mask)] + 1
    }
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val tokenizer = StringTokenizer(jin.readLine())
    val n = tokenizer.nextToken().toInt()
    val k = tokenizer.nextToken().toInt()
    val digit = Array(n + 1) { IntArray(k + 1) { -1 } }
    digit[0][0] = 0
    val scoreboard = Array(n) { jin.readLine().toInt(2) }
    for (j1 in 1..n) {
        for (j2 in 0..k) {
            for (d in 0..9) {
                if (BITMASKS[d] or scoreboard[n - j1] == BITMASKS[d]) {
                    val amt = bitAMT[BITMASKS[d] xor scoreboard[n - j1]]
                    if (j2 >= amt && digit[j1 - 1][j2 - amt] != -1) {
                        digit[j1][j2] = d
                    }
                }
            }
        }
    }
    if (digit[n][k] == -1) {
        println(-1)
    } else {
        val answer = StringBuilder()
        var kt = k
        for (j in n downTo 1) {
            answer.append(digit[j][kt])
            kt -= bitAMT[BITMASKS[digit[j][kt]] xor scoreboard[n - j]]
        }
        println(answer)
    }
}