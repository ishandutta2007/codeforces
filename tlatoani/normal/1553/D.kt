import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val s = readLine()!!.reversed()
        val t = readLine()!!.reversed()
        val stack = Stack<Char>()
        var remove = false
        var answer = "nO"
        for (letter in s) {
            if (remove) {
                stack.pop()
                remove = false
            } else {
                if (letter != t[stack.size]) {
                    remove = true
                }
                stack.push(letter)
                if (!remove && stack.size == t.length) {
                    answer = "yEs"
                    break
                }
            }
        }
        println(answer)
    }
}