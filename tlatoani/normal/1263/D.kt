import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val passwords = IntArray(26)
    for (j in 1..n) {
        var password = 0
        for (chara in jin.next()) {
            password = password or (1 shl (chara - 'a'))
        }
        for (k in 0..25) {
            if ((password and (1 shl k)) != 0) {
                passwords[k] = passwords[k] or password
            }
        }
    }
    var components = 0
    val visited = BooleanArray(26)
    for (k in 0..25) {
        if (!visited[k] && passwords[k] != 0) {
            components++
            val stack = Stack<Int>()
            visited[k] = true
            stack.push(k)
            while (!stack.isEmpty()) {
                val l = stack.pop()
                for (m in 0..25) {
                    if (!visited[m] && (passwords[l] and (1 shl m)) != 0) {
                        visited[m] = true
                        stack.push(m)
                    }
                }
            }
        }
    }
    println(components)
}