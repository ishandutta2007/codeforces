import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val out = StringBuilder()
    for (c in 1..jin.readLine().toInt()) {
        val stack = Stack<Char>()
        for (chara in jin.readLine()) {
            if (chara == 'A' || stack.isEmpty() || stack.peek() == 'B') {
                stack.push(chara)
            } else {
                stack.pop()
            }
        }
        var answer = 0
        while (stack.isNotEmpty() && stack.peek() == 'A') {
            answer++
            stack.pop()
        }
        answer += stack.size and 1
        out.appendln(answer)
    }
    print(out)
}