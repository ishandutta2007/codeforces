import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val s = jin.readLine().reversed()
    val curr = CharArray(s.length)
    var k = 0
    val stack = Stack<Char>()
    stack.push('a' - 1)
    val out = StringBuilder()
    var parity = false
    var prev = 'a' - 1
    for (chara in s) {
        if (prev != chara) {
            parity = false
            prev = chara
        }
        parity = !parity
        if (stack.peek() == chara) {
            stack.pop()
        }
        if (chara < stack.peek() || parity) {
            curr[k] = chara
            k++
            stack.push(chara)
        } else {
            k--
            if (k > 0 && curr[k - 1] == chara) {
                stack.push(chara)
            }
        }
        out.appendln()
        if (k <= 10) {
            for (j in 0 until k) {
                out.append(curr[j])
            }
        } else {
            for (j in 0 until 2) {
                out.append(curr[j])
            }
            out.append("...")
            for (j in k - 5 until k) {
                out.append(curr[j])
            }
        }
        out.append(' ').append(k.toString().reversed())
    }
    print(out.reversed())
}