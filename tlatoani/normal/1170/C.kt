import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    for (c in 1..jin.nextLine().toInt()) {
        val s = jin.nextLine()
        val t = jin.nextLine()
        var i = 0
        var answer = true
        for (chara in t) {
            if (i >= s.length) {
                answer = false
                break
            }
            if (s[i] == chara) {
                i++
            } else {
                if (chara == '-' || i + 1 >= s.length || s[i] == '+' || s[i + 1] == '+') {
                    answer = false
                    break
                }
                i += 2
            }
        }
        println(if (answer && i == s.length) "YES" else "NO")
    }
}