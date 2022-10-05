import java.util.*

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(" ").map { it.toInt() }
        val xTokenizer = StringTokenizer(readLine()!!)
        val dirTokenizer = StringTokenizer(readLine()!!)
        val robots = Array(n) {
            val x = xTokenizer.nextToken().toInt()
            val dir = dirTokenizer.nextToken() == "L"
            Robot(x, dir, it)
        }
        val answer = IntArray(n) { -1 }
        solve(m, robots.filter { it.x % 2 == 0 }, answer)
        solve(m, robots.filter { it.x % 2 == 1 }, answer)
        println(answer.joinToString(" "))
    }
}

data class Robot(val x: Int, val left: Boolean, val index: Int)

fun solve(m: Int, robots: List<Robot>, answer: IntArray) {
    val robots = robots.sortedWith(compareBy({ it.x }, { it.left }))
    val stack = Stack<Robot>()
    for (robot in robots) {
        if (robot.left && stack.isNotEmpty() && !stack.peek().left) {
            answer[robot.index] = (robot.x - stack.peek().x) / 2
            answer[stack.pop().index] = answer[robot.index]
        } else {
            stack.push(robot)
        }
    }
    stack.toList()
    val left = stack.filter { it.left }
    for (j in 1 until left.size step 2) {
        answer[left[j].index] = (left[j - 1].x + left[j].x) / 2
        answer[left[j - 1].index] = answer[left[j].index]
    }
    val right = stack.filter { !it.left }.reversed()
    for (j in 1 until right.size step 2) {
        answer[right[j].index] = m - ((right[j - 1].x + right[j].x) / 2)
        answer[right[j - 1].index] = answer[right[j].index]
    }
    if (left.size % 2 == 1 && right.size % 2 == 1) {
        answer[left.last().index] = (m + left.last().x + (m - right.last().x)) / 2
        answer[right.last().index] = answer[left.last().index]
    }
}