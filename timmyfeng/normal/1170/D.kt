import java.util.*

fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }
    val m = a.count { it == -1 }
    val que = LinkedList<Int>()
    val ans = Array(m) { mutableListOf<Int>() }
    for (i in 0 until m) {
        que.offer(i)
    }
    for (i in a) {
        val u = que.poll()
        if (i != -1) {
            ans[u].add(i)
            que.offer(u)
        }
    }
    println(m)
    for (i in ans) {
        println("${i.size} ${i.joinToString(" ")}")
    }
}