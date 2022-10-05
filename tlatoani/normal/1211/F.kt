import java.util.*

fun main() {
    val jin = Scanner(System.`in`)
    val n = jin.nextInt()
    val kotlin = "kotlin"
    val place = mutableMapOf<Char, Int>()
    for (i in 0..5) {
        place[kotlin[i]] = i
    }
    val adj = Array(6) { mutableListOf<Pair<Int, Int>>() }
    for (i in 1..n) {
        val piece = jin.next()
        adj[place[piece[0]]!!].add(Pair((place[piece.last()]!! + 1) % 6, i))
    }
    //println("adj = ${adj.contentToString()}")
    val stack1 = Stack<Pair<Int, Int>>()
    stack1.push(Pair(0, 0))
    val stack2 = Stack<Int>()
    while (!stack1.isEmpty()) {
        val list = adj[stack1.peek().first]
        if (list.isEmpty()) {
            stack2.push(stack1.pop().second)
        } else {
            stack1.push(list.last())
            list.removeAt(list.size - 1)
        }
    }
    stack2.pop()
    val answer = StringJoiner(" ")
    while (!stack2.isEmpty()) {
        answer.add(stack2.pop().toString())
    }
    println(answer)
}