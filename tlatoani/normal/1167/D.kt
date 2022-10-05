import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    jin.nextInt()
    val answer = StringBuilder()
    var bit = 0
    for (chara in jin.next()) {
        if (chara == '(') {
            bit = 1 - bit
            answer.append(bit)
        } else {
            answer.append(bit)
            bit = 1 - bit
        }
    }
    println(answer)
}