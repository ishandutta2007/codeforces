import kotlin.math.min

fun main() {
    readLine()
    val last = IntArray(52)
    var answer = 115115115
    var k = 0
    val s = readLine()!!
    for (letter in 'a'..'z') {
        if (letter !in s) {
            last[letter - 'a'] = 115115115
        }
    }
    for (letter in 'A'..'Z') {
        if (letter !in s) {
            last[letter - 'A' + 26] = 115115115
        }
    }
    for (chara in s) {
        k++
        last[if (chara >= 'a') (chara - 'a') else (chara - 'A' + 26)] = k
        if (last.min()!! > 0) {
            answer = min(answer, k - last.min()!! + 1)
        }
    }
    println(answer % 115115115)
}