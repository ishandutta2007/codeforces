import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        readLine()
        val stack = Stack<Pair<String, Int>>()
        println("1")
        stack.push(Pair("", 1))
        repeat(n - 1) {
            val k = readLine()!!.toInt()
            if (k == 1) {
                val (s, j) = stack.peek()
                stack.push(Pair("$s$j.", k))
            } else {
                while (stack.peek().second != k - 1) {
                    stack.pop()
                }
                val s = stack.pop().first
                stack.push(Pair(s, k))
            }
            println("${stack.peek().first}$k")
        }
    }
}