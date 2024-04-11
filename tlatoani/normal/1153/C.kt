import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    if (n % 2 == 1) {
        println(":(")
        return
    }
    val s = jin.next()
    var open = 0
    for (chara in s) {
        if (chara == '(') {
            open++
        }
    }
    if (open > n / 2) {
        println(":(")
        return
    }
    val answer = StringBuilder()
    var y = 0
    for (j in 0 until n) {
        val chara = s[j]
        if (chara == '(' || (chara == '?' && open < n / 2)) {
            answer.append('(')
            y++
            if (chara == '?') {
                open++
            }
        } else {
            answer.append(')')
            y--
        }
        if (j < n - 1 && y <= 0) {
            println(":(")
            return
        }
    }
    println(answer)
}