import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

const val NULL = 0.toChar()

fun main() {
    val jin = BufferedReader(InputStreamReader(System.`in`))
    val n = jin.readLine().toInt()
    val grid = Array(n) {
        val tokenizer = StringTokenizer(jin.readLine())
        Array(n) {
            val y = tokenizer.nextToken().toInt() - 1
            val x = tokenizer.nextToken().toInt() - 1
            Pair(y, x)
        }
    }
    var answer = Array(n) { CharArray(n) }
    val stack = Stack<Int>()
    for (y in 0 until n) {
        for (x in 0 until n) {
            if (grid[y][x] == Pair(y, x)) {
                answer[y][x] = 'X'
                stack.push(y)
                stack.push(x)
                while (stack.isNotEmpty()) {
                    val a = stack.pop()
                    val b = stack.pop()
                    if (b > 0 && answer[b - 1][a] == NULL && grid[b - 1][a] == Pair(y, x)) {
                        answer[b - 1][a] = 'D'
                        stack.push(b - 1)
                        stack.push(a)
                    }
                    if (b < n - 1 && answer[b + 1][a] == NULL && grid[b + 1][a] == Pair(y, x)) {
                        answer[b + 1][a] = 'U'
                        stack.push(b + 1)
                        stack.push(a)
                    }
                    if (a > 0 && answer[b][a - 1] == NULL && grid[b][a - 1] == Pair(y, x)) {
                        answer[b][a - 1] = 'R'
                        stack.push(b)
                        stack.push(a - 1)
                    }
                    if (a < n - 1 && answer[b][a + 1] == NULL && grid[b][a + 1] == Pair(y, x)) {
                        answer[b][a + 1] = 'L'
                        stack.push(b)
                        stack.push(a + 1)
                    }
                }
            }
        }
    }
    for (y in 0 until n) {
        for (x in 0 until n) {
            if (answer[y][x] == NULL) {
                if (grid[y][x].first == -2) {
                    if (y > 0 && grid[y - 1][x].first == -2) {
                        answer[y][x] = 'U'
                    } else if (y < n - 1 && grid[y + 1][x].first == -2) {
                        answer[y][x] = 'D'
                    } else if (x > 0 && grid[y][x - 1].first == -2) {
                        answer[y][x] = 'L'
                    } else if (x < n - 1 && grid[y][x + 1].first == -2) {
                        answer[y][x] = 'R'
                    } else {
                        println("INVALID")
                        return
                    }
                } else {
                    println("INVALID")
                    return
                }
            }
        }
    }
    println("VALID")
    println(answer.map { String(it) }.joinToString("\n"))
}