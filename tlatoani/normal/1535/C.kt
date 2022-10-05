import kotlin.math.max

fun main() {
    repeat(readLine()!!.toInt()) {
        var answer = 0L
        var length0 = 0L
        var length1 = 0L
        for (chara in readLine()!!) {
            val x = if (chara == '0' || chara == '?') length1 + 1L else 0L
            val y = if (chara == '1' || chara == '?') length0 + 1L else 0L
            length0 = x
            length1 = y
            answer += max(length0, length1)
        }
        println(answer)
    }
}